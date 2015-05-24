using namespace std;

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

#include "Recognize.h"
#include "Draw.h"

Draw *draw = new Draw();
Recognize *recognize = new Recognize();

static inline bool isNumber(const string &str) {
    string::const_iterator it = str.begin();
    while (it != str.end() && isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

void drawHelp() {
    printf("draw [-s width height] [-p top left] [-h lineHeight] [-n lineNumber] [-f file]\n");
}

void recognizeHelp() {
    printf("recognize [-p top left] [-h lineHeight] [-f file]\n");
}

int main(int argc, char** argv) {

    int code = 1;

    int width = 100, height = 100, top = 0, left = 0, lineHeight = 1, lineNumber = 10;
    char *file = (char*) "file.pbm";

    char command[100] = "";

    printf("Lines program launched. Enter command or 'help'\n");

    while (code) {

        fgets(command, 50, stdin);

        char *tokenizedCommand = strtok(command, "\n");
        tokenizedCommand = strtok(tokenizedCommand, " ");

        if ((strcmp(tokenizedCommand, "quit") == 0) || (strcmp(tokenizedCommand, "q") == 0)) {
            printf("Goodbye!\n");
            code = 0;
        }

        if ((strcmp(tokenizedCommand, "help") == 0) || (strcmp(tokenizedCommand, "h") == 0)) {
            printf("Available commands:\n");
            printf("'help' or 'h' - this list\n");
            printf("'draw' or 'd' - draw lines (show parameters list)\n");
            printf("'recognize' or 'r' - recognize from file (show parameters list)\n");
            printf("'quit' or 'q' - exit program\n");
        }

        if ((strcmp(tokenizedCommand, "draw") == 0) || (strcmp(tokenizedCommand, "d") == 0)) {
            if ((tokenizedCommand = strtok(NULL, " ")) == NULL) {
                drawHelp();
                continue;
            } else {
                do {
                    if (strcmp(tokenizedCommand, "-s") == 0 && (tokenizedCommand = strtok(NULL, " ")) != NULL) {
                        if (isNumber(tokenizedCommand)) {
                            width = atoi(tokenizedCommand);
                        }
                        else {
                            cout << "Incorrect -s parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        if ((tokenizedCommand = strtok(NULL, " ")) != NULL) {
                            if (isNumber(tokenizedCommand)) {
                                height = atoi(tokenizedCommand);
                            }
                            else {
                                cout << "Incorrect -s parameter: " << tokenizedCommand << endl;
                                drawHelp();
                            }
                        }
                        continue;
                    }
                    if (strcmp(tokenizedCommand, "-p") == 0 && (tokenizedCommand = strtok(NULL, " ")) != NULL) {
                        if (isNumber(tokenizedCommand)) {
                            top = atoi(tokenizedCommand);
                        }
                        else {
                            cout << "Incorrect -p parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        if ((tokenizedCommand = strtok(NULL, " ")) != NULL) {
                            if (isNumber(tokenizedCommand)) {
                                left = atoi(tokenizedCommand);
                            }
                            else {
                                cout << "Incorrect -p parameter: " << tokenizedCommand << endl;
                                drawHelp();
                            }
                        }
                        continue;
                    }
                    if (strcmp(tokenizedCommand, "-h") == 0 && (tokenizedCommand = strtok(NULL, " ")) != NULL) {
                        if (isNumber(tokenizedCommand)) {
                            lineHeight = atoi(tokenizedCommand);
                        }
                        else {
                            cout << "Incorrect -h parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        continue;
                    }
                    if (strcmp(tokenizedCommand, "-n") == 0 && (tokenizedCommand = strtok(NULL, " ")) != NULL) {
                        if (isNumber(tokenizedCommand)) {
                            lineNumber = atoi(tokenizedCommand);
                        }
                        else {
                            cout << "Incorrect -n parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        continue;
                    }
                    if (strcmp(tokenizedCommand, "-f") == 0 && (tokenizedCommand = strtok(NULL, " ")) != NULL) {
                        file = tokenizedCommand;
                    }
                    tokenizedCommand = strtok(NULL, " ");
                } 
                while (tokenizedCommand != NULL);
            }
            continue;
        }

        if ((strcmp(tokenizedCommand, "recognize") == 0) || (strcmp(tokenizedCommand, "r") == 0)) {
            if ((tokenizedCommand = strtok(NULL, " ")) == NULL) {
                drawHelp();
                continue;
            } else {
                do {
                    
                    tokenizedCommand = strtok(NULL, " ");
                } 
                while (tokenizedCommand != NULL);
            }
            continue;
        }
        
        if (strcmp(tokenizedCommand, "debug") == 0) {
            cout << "width = " << width << endl;
            cout << "height = " << height << endl;
            cout << "top = " << top << endl;
            cout << "left = " << left << endl;
            cout << "lineHeight = " << lineHeight << endl;
            cout << "lineNumber = " << lineNumber << endl;
            cout << "file = " << file << endl;
            continue;
        }
    }
    
    return code;
}
