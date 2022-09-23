#include <stdlib.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>


struct termios old_tio, new_tio;
unsigned int width=15;

/* get input {{{ */
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
/* get input }}} */

/* parts {{{ */
void openurl() {

    printf("Click on Browser");

    sleep(1);

    system("xdotool key --clearmodifiers ctrl+t");

    char *url = "xdotool type https://yewtu.be";
    system(url);
    //system("xdotool type %c");

    system("xdotool key --clearmodifiers Return");
}
/* parts }}} */

/* menu {{{ */
void printmenu(register unsigned int select) {
    register unsigned int e = 1;

    printf("\n");
    for (e=1; e<=4; e++) {
        printf("%*c",width,width);
        if (select == e) {
            printf("\033[1;37m>");
        }
        if (e == 1) { /* space to remove extras*/
            printf("OPEN  \033[0;0m\n");
        } else if (e == 2) {
            printf("URL  \033[0;0m\n");
        } else if (e == 3) {
            printf("SETTINGS  \033[0;0m\n");
        } else if (e == 4) {
            printf("QUIT  \033[0;0m\n");
        } else {}
    }
    /* if ( there is an error) {} */
    printf(":: ");
}
void menu() {
    printmenu(select);

    register unsigned int select = 1;
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
            break;
        } else if (input == 5) {
            if (select == 1) {
                printf("start");
            } else if (select == 2) {
                openurl();
            } else {
                break;
            }
        } else {}
        sleep(0.25);

        printf("\x1b[5A"); /* # = menu options + 1*/
        printmenu(select);
    } while (select != 0);
}

/* menu }}} */


int main() {
    /* termios */
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);


    printf(" ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗\n██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║\n██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║\n██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║\n╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║\n ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝\n");

    menu();
    //printf("\x001b[1000D welcome to");

    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); /* restore former settings */
    return 0;
}
