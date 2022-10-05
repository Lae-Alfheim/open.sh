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
#define EXIT    6
#define ENTER   10
#define CLIENTMAX 4

/* Boolean variable type */
typedef enum { F, T } boolean;

/* Some are defined in config.h*/
struct termios old_tio, new_tio; /* for termios */
char *url;
char urlout[sizeof(url)+14];
/* }}} */
/* {{{ Quit */
void quit() {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); /* Restore Former Settings */
        exit(0);
}
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
            value = 6; /* esc */ }
    } else if (input == 119 || input == 107) { value = 1;
    } else if (input == 114 || input == 106 || input == 5) { value = 2;
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
/* Print Menu {{{ */
void printMenu(char names[][128], int number, int selection) {
    printf("\x1b[%dA", number + 2); /* MOVE BACK UP */

    register int i = 1;
    printf("\n");
    for (i=0; i<number; i++) {
        printf("%*c",WIDTH,WIDTH); /* The begining Width Menu */
        if (i == selection - 1) {
            printf("\033[1;37m>");
        }
            printf("%s\033[0;0m", names[i]);
            printf("\033[0;0m%*c\n",CLEAR,CLEAR); /* clearing after print */
    }
    printf("\033[0;0m%*c\n",CLEAR,CLEAR); /* clearing after print */

        //char string[3][128] = {"FIRST", "SECOND", "THIRD"};
        //printMenu(string, 3, 1);
}
/* }}} */

/* Client {{{ */

/* Music {{{ */
int music(boolean play) {
    if(play == T) {
        system(MUSIC);
        play = F;
        printf("Playing Music :: ON ");
    } else {
        system(MUSICSTOP);
        play = T;
        printf("Killed Music :: OFF ");
    }
    return play;
}
/* }}}*/
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
/* Control Client Menu {{{ */
void clientMenuControl() {
    usleep(25000); /* 25 milliseconds */
    char names[CLIENTMAX][128] = {"VIDEO", "MUSIC", "BROWSER", "QUIT"};
    unsigned int select = 0;
    boolean playMusic = T;
    printf("\n\n\n\n\n\n\n");
    do {
        printMenu(names, CLIENTMAX, select);
        int input = getinput();
        if (input == 1 && select > 1) { select--; }
        else if (input == 2) {
            if (select < CLIENTMAX) { select++; }
            else { select = 1; }
        }
        else if (input == 0) {
            printf("\n");
            quit();
        } else if (input == ENTER) {
            if (select == 1) {
                system("freetube");
                callServer();
            } else if (select == 2) {
                playMusic = music(playMusic);
            } else if (select == 3) {
            } else {
                quit();
            }
        } else {} /* Just in case implement later, stops a bug */
        usleep(25000); /* 25 milliseconds */
    } while (1);
}
/* }}} */
void client() { /* TODO: flashy client screen */
    printf("OPEN.SH Client");
    clientMenuControl();

}
/* }}} */

/* Server {{{ */

#define SERVERMAX 5
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
/* Menu {{{ */
void mainMenu() {
    register unsigned int select = 0;
    char names[SERVERMAX][128] = {"OPEN", "URL", "LOG", "CLIENT", "QUIT"};
    printf("\n\n\n\n\n\n\n");
    do {
        printMenu(names, SERVERMAX, select);
        int input = getinput();
        if (input == 1 && select > 1) { select--; }
        else if (input == 2) {
            if (select < SERVERMAX) { select++; }
            else { select = 1; }
        }
        else if (input == 0) {
            printf("\n");
            quit();
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
                quit();
            }
        } else {} /* Just in case implement later, stops a bug */
        usleep(25000);
    } while (select != 0);
}

/* }}} */
/* }}} */
/* }}} */

/*
 * MAIN
 */

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (runServer == T) {
            printf("Server Not Working At momeent\nChange in config.h");
        }
            printf("%s", argv[1]);
            url = argv[1];
            openurl();
    } else if (argc == 1) {
        /* For Good Input */
        tcgetattr(STDIN_FILENO, &old_tio);
        new_tio = old_tio;
        new_tio.c_lflag &= (~ICANON & ~ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);


        /* Printf Logo*/
        printf(" ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗\n"
               "██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║\n"
               "██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║\n"
               "██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║\n"
               "╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║\n"
               " ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝\n");

        mainMenu();

        /* END */
        quit();
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); /* Restore Former Settings */
        return 0;

    }

    return 0;

}
