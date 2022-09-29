/*
 * open.sh
 *
 * A add-on script for newsboat, with cross computer URL sharing,
 * and every day log support, along with proxying through tor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "config.h"


/* Global Variable {{{ */

struct termios old_tio, new_tio;
    /* WIDTH is defined in config.h*/

char *url;
char urlout[sizeof(url)+14];

/* }}} */

/* Get Input {{{ */
int getinput() {
    int value;
    char input = getchar();
    if (input == 27) {
        if (getchar() == 91) {
            switch(getchar()) {
                case 65: /* up */
                    value = 1;
                    break;
                case 66: /* down */
                    value = 2;
                    break;
                case 67: /* right */
                    value = 3;
                    break;
                case 68: /* left */
                    value = 4;
                    break;
            }
        } else {
            value = 6; /* esc */
        }
    } else if (input == 119 || input == 107) {
        value = 1;
    } else if (input == 114 || input == 106) {
        value = 2;
    } else if (input == 115 || input == 108 ) {
        value = 3;
    } else if (input == 97 || input == 104 ) {
        value = 4;
    }
    else if (input == 113) {
        value = 0;
    } else {
        value = 5;
    }
    return value;
}
/* }}} */

/* Open URL {{{ */
void openurl() {

    sleep(3);

    system("xdotool key --clearmodifiers ctrl+t");

    sprintf(urlout,"xdotool type %s", url);
    printf("%s", urlout);
    //url = "xdotool type" + url;
    system(urlout);
    //system("xdotool type %c");

    system("xdotool key --clearmodifiers Return");
}
/* }}} */

/* Menu {{{ */
void printmenu(register unsigned int select) {
    register unsigned int e = 1;

    printf("\n");
    for (e=1; e<=4; e++) {
        printf("%*c",WIDTH,WIDTH);
        if (select == e) {
            printf("\033[1;37m>");
        }
        if (e == 1) { /* space to remove extras*/
            printf("OPEN    \033[0;0m\n");
        } else if (e == 2) {
            printf("URL    \033[0;0m\n");
        } else if (e == 3) {
            printf("LOG    \033[0;0m\n");
        } else if (e == 4) {
            printf("QUIT    \033[0;0m\n");
        } else {}
    }
    /* if ( there is an error) {} */
    printf(":: ");
}
void menu() {

    register unsigned int select = 1;
    printmenu(select);

    do {
        int input = getinput();
        if (input == 1) {
            if (select > 1) {
                select--;
            }
        } else if (input == 2) {
            if (select < 4) {
                select++;
            }
        } else if (input == 0) {
            printf("\n");
            exit(0);
        } else if (input == 5) {
            if (select == 1) {
                system(NEWSBOAT);
            } else if (select == 2) {
                select = 1;
                printf("Click on Browser");
                url = DEFAULTURL;
                openurl();
            } else if (select == 3) {
                select = 1;
                system("nvim $HOME/dox/NOTES/log.md");
            } else {
                printf("\n");
                exit(0);
            }
        } else {} /* Just in case implement later, stops a bug */
        usleep(25000);

        printf("\x1b[5A"); /* # = menu options + 1*/
        printmenu(select);
    } while (select != 0);
}

/* }}} */

/*
 * MAIN
 */

int main(int argc, char *argv[]) {

    if (argc == 2) {
        printf("%s", argv[1]);
        url = argv[1];
        openurl();
    } else if (argc == 1) {
        /* termios */
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;
        new_tio.c_lflag &= (~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

        printf(" ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗\n██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║\n██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║\n██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║\n╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║\n ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝\n");

        menu();

        /* END */
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); /* restore former settings */

    }

    return 0;

}
