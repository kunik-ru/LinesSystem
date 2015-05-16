using namespace std;

#include <cstdlib>
#include <stdio.h>
#include <string.h>

#include "Recognize.h"
#include "Draw.h"

Draw *draw = new Draw();
Recognize *recognize = new Recognize();

int main(int argc, char** argv) {

    int code = 1;

    char command[30] = "";

    printf("Lines program launched. Enter command or 'help'\n");

    while (code) {

        scanf("%s", command);

        if ((strcmp(command, "help") == 0) || (strcmp(command, "h") == 0)) {
            printf("Available commands:\n");
            printf("'help' or 'h' - this list\n");
            printf("'draw' or 'd' - draw lines (show parameters list)\n");
            printf("'recognize' or 'r' - recognize from file (show parameters list)\n");
            printf("'quit' or 'q' - exit program\n");
        }

        if ((strcmp(command, "draw") == 0) || (strcmp(command, "d") == 0)) {

        }

        if ((strcmp(command, "recognize") == 0) || (strcmp(command, "r") == 0)) {

        }

        if ((strcmp(command, "quit") == 0) || (strcmp(command, "q") == 0)) {
            printf("Goodbye!\n");
            code = 0;
        }
    }

    return code;
}
