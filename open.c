/*
 * open.sh
 *
 * A add-on script for newsboat, with cross computer URL sharing,
 * and every day log support, along with proxying through tor.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
/* Client and Server*/
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
/* Configuration File */
#include "config.h"




/* Global Variables {{{ */
#define QUIT    0
#define UP      1
#define DOWN    2
#define RIGHT   3
#define LEFT    4
#define ENTER   10
/* Some are defined in config.h*/
struct termios old_tio, new_tio; /* for termios */
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
    } else if (input == 119 || input == 107 || input == 5) { value = 1;
    } else if (input == 114 || input == 106) { value = 2;
    } else if (input == 115 || input == 108 ) { value = 3;
    } else if (input == 97 || input == 104 ) { value = 4;
    }else if (input == 113) {
        value = 0;
    } else {
        value = 10;
    }
    return value;
}
/* }}} */

/* Client {{{ */
/* Print Client Menu {{{ */
void printClientMenu(register unsigned int select) {
    register unsigned int e = 1;
    printf("\n");
    for (e=1; e<=5; e++) {
        printf("%*c",WIDTH,WIDTH);
        if (select == e) {
            printf("\033[1;37m>");
        }
        if (e == 1) { /* space to remove extras*/
            printf("VIDEO");
        } else if (e == 2) {
            printf("MUSIC");
        } else if (e == 3) {
            printf("BROWSER");
        } else {}
        printf("\033[0;0m%*c\n",CLEAR,CLEAR);
    }
    printf("\x1b[6A"); /* #=menu options+2 for overflow*/
}
/* }}} */
/* Control Client Menu {{{ */
void clientMenuControl() {
    unsigned int select = 0;
    printClientMenu(select);
    do {
        int input = getinput();
        if (input == 1 && select > 1) { select--; }
        else if (input == 2 && select < 3) { select++; }
        else if (input == 0) {
            printf("\n");
            exit(0);
        } else if (input == ENTER) {
            if (select == 1) {
            } else if (select == 2) {
            } else {
                exit(0);
            }
        } else {} /* Just in case implement later, stops a bug */
        usleep(25000); /* 25 milliseconds */
        printClientMenu(select);
    } while (1);
}
/* }}} */
/* callServer {{{*/
void callServer() {
    int sockD = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001); // use some unused port number
    servAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr,
            sizeof(servAddr));

    if (connectStatus == -1) {
        printf("Error...\n");
    } else {
        char strData[255];
        recv(sockD, strData, sizeof(strData), 0);
        printf("Message: %s", strData);
    }
}

/* }}} */
void client() { /* TODO: flashy client screen */
    printf("OPEN.SH Client");
    clientMenuControl();

}
/* }}} */

/* Server {{{ */

/* Open URL {{{ */
void openurl() {

    sleep(3);

    system("xdotool key --clearmodifiers ctrl+t");

    snprintf(urlout, sizeof(urlout),"xdotool type %s", url);
    printf("%s", urlout);
    //url = "xdotool type" + url;
    system(urlout);
    //system("xdotool type %c");

    system("xdotool key --clearmodifiers Return");
}
/* }}} */
/* Print Menu {{{ */
void printmenu(register unsigned int select) {
    register unsigned int e = 1;

    printf("\n");
    for (e=1; e<=5; e++) {
        printf("%*c",WIDTH,WIDTH);
        if (select == e) {
            printf("\033[1;37m>");
        }
        if (e == 1) { /* space to remove extras*/
            printf("open");
        } else if (e == 2) {
            printf("url");
        } else if (e == 3) {
            printf("log");
        } else if (e == 4) {
            printf("client");
        } else if (e == 5) {
            printf("quit");
        } else {}
        printf("\033[0;0m%*c\n",CLEAR,CLEAR);
    }
    /* if ( there is an error) {} */
    printf(":: \n:: ");
}
/* }}} */
/* Menu {{{ */
void afterPartRun() { printf("\x1b[7A"); /* #=menu options+2 for overflow*/ }
void mainMenu() {
    register unsigned int select = 0;
    printmenu(select);
    do {
        int input = getinput();
        if (input == 1) {
            if (select > 1) {
                select--;
            }
        } else if (input == 2) {
            if (select < 10) {
                select++;
            }
        } else if (input == 0) {
            printf("\n");
            exit(0);
        } else if (input == 10) {
            if (select == 1) {
                system(NEWSBOAT);
            } else if (select == 2) {
                select = 1;
                printf("Click on Browser");
                url = DEFAULTURL;
                openurl();
            } else if (select == 3) {
                select = 1;
                system(LOG);
            } else if (select == 4) {
                select = 1;;
                client();
            } else {
                printf("\n");
                exit(0);
            }
        } else {} /* Just in case implement later, stops a bug */
        usleep(25000);
        printf("\x1b[7A"); /* #=menu options+2 for overflow*/
        printmenu(select);
    } while (select != 0);
}

/* }}} */
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

        /* for good imput */
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;
        new_tio.c_lflag &= (~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

        /* Pritf Logo*/
        printf(" ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗\n"
               "██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║\n"
               "██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║\n"
               "██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║\n"
               "╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║\n"
               " ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝\n");

        mainMenu();

        /* END */
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); /* restore former settings */
        return 0;

    }

    return 0;

}
