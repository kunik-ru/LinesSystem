#include "Recognize.h"
#include "Draw.h"

using namespace std;

Draw *draw = new Draw();
Recognize *recognize = new Recognize();

inline bool isNumber(const string &str) {
    string::const_iterator it = str.begin();
    while (it != str.end() && isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

void drawHelp() {
    cout << "draw [-s width height] [-p top left] [-h lineHeight] [-n lineNumber] [-f file]" << endl;
}

void recognizeHelp() {
    cout << "recognize [-p top left] [-h lineHeight] [-f file]" << endl;
    ;
}

int main(int argc, char** argv) {

    int code = 1;

    int width = 100, height = 100, top = 0, left = 0, lineHeight = 1, lineNumber = 10;

    char* file = (char*) malloc(20 * sizeof (char));

    strcpy(file, "file.pbm");

    char* command = (char*) malloc(200 * sizeof (char));

    cout << "Lines program launched. Enter command or 'help'" << endl;

    while (code) {

        fgets(command, 50, stdin);

        char *tokenizedCommand = strtok(command, "\n");
        tokenizedCommand = strtok(tokenizedCommand, " ");

        if ((strcmp(tokenizedCommand, "quit") == 0) || (strcmp(tokenizedCommand, "q") == 0)) {
            cout << "Goodbye!" << endl;
            code = 0;
        }

        if ((strcmp(tokenizedCommand, "help") == 0) || (strcmp(tokenizedCommand, "h") == 0)) {
            cout << "Available commands:" << endl;
            cout << "'help' or 'h' - this list" << endl;
            cout << "'draw' or 'd' - draw lines (show parameters list)" << endl;
            cout << "'recognize' or 'r' - recognize from file (show parameters list)" << endl;
            cout << "'quit' or 'q' - exit program" << endl;
        }

        if ((strcmp(tokenizedCommand, "draw") == 0) || (strcmp(tokenizedCommand, "d") == 0)) {
            if ((tokenizedCommand = strtok(NULL, " ")) == NULL) {
                drawHelp();
                continue;
            } else {
                do {
                    if ((strcmp(tokenizedCommand, "-s") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (isNumber(tokenizedCommand)) {
                            width = atoi(tokenizedCommand);
                        } else {
                            cout << "Incorrect -s parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        if ((tokenizedCommand = strtok(NULL, " ")) != NULL) {
                            if (isNumber(tokenizedCommand)) {
                                height = atoi(tokenizedCommand);
                            } else {
                                cout << "Incorrect -s parameter: " << tokenizedCommand << endl;
                                drawHelp();
                            }
                        }
                        continue;
                    }
                    if ((strcmp(tokenizedCommand, "-p") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (isNumber(tokenizedCommand)) {
                            top = atoi(tokenizedCommand);
                        } else {
                            cout << "Incorrect -p parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        if ((tokenizedCommand = strtok(NULL, " ")) != NULL) {
                            if (isNumber(tokenizedCommand)) {
                                left = atoi(tokenizedCommand);
                            } else {
                                cout << "Incorrect -p parameter: " << tokenizedCommand << endl;
                                drawHelp();
                            }
                        }
                        continue;
                    }
                    if ((strcmp(tokenizedCommand, "-h") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (isNumber(tokenizedCommand)) {
                            lineHeight = atoi(tokenizedCommand);
                        } else {
                            cout << "Incorrect -h parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        continue;
                    }
                    if ((strcmp(tokenizedCommand, "-n") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (isNumber(tokenizedCommand)) {
                            lineNumber = atoi(tokenizedCommand);
                        } else {
                            cout << "Incorrect -n parameter: " << tokenizedCommand << endl;
                            drawHelp();
                        }
                        continue;
                    }
                    if ((strcmp(tokenizedCommand, "-f") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (strlen(tokenizedCommand) <= 20) {
                            strcpy(file, tokenizedCommand);
                        } else {
                            cout << "File name too long" << endl;
                        }
                    }
                    tokenizedCommand = strtok(NULL, " ");
                } while (tokenizedCommand != NULL);

                draw -> draw(width, height, top, left, lineHeight, lineNumber, file);
                
            }
            continue;
        }

        if ((strcmp(tokenizedCommand, "recognize") == 0) || (strcmp(tokenizedCommand, "r") == 0)) {
            if ((tokenizedCommand = strtok(NULL, " ")) == NULL) {
                recognizeHelp();
                continue;
            } else {
                do {
                    if ((strcmp(tokenizedCommand, "-p") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (isNumber(tokenizedCommand)) {
                            top = atoi(tokenizedCommand);
                        } else {
                            cout << "Incorrect -p parameter: " << tokenizedCommand << endl;
                            recognizeHelp();
                        }
                        if ((tokenizedCommand = strtok(NULL, " ")) != NULL) {
                            if (isNumber(tokenizedCommand)) {
                                left = atoi(tokenizedCommand);
                            } else {
                                cout << "Incorrect -p parameter: " << tokenizedCommand << endl;
                                recognizeHelp();
                            }
                        }
                        continue;
                    }
                    if ((strcmp(tokenizedCommand, "-h") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (isNumber(tokenizedCommand)) {
                            lineHeight = atoi(tokenizedCommand);
                        } else {
                            cout << "Incorrect -h parameter: " << tokenizedCommand << endl;
                            recognizeHelp();
                        }
                        continue;
                    }
                    if ((strcmp(tokenizedCommand, "-f") == 0) && ((tokenizedCommand = strtok(NULL, " ")) != NULL)) {
                        if (strlen(tokenizedCommand) <= 20) {
                            strcpy(file, tokenizedCommand);
                        } else {
                            cout << "File name too long" << endl;
                        }
                        continue;
                    }
                    tokenizedCommand = strtok(NULL, " ");
                } while (tokenizedCommand != NULL);

                //Here recognize

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

    delete(file);
    delete(command);

    return code;
}
