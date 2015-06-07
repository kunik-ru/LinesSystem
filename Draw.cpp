#include "Draw.h"

using namespace std;

Draw::Draw() {
    
}

void Draw::freeglutInit(const int& windowWidth, const int& windowHeight) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) / 2) - (windowWidth / 2),
            (glutGet(GLUT_SCREEN_HEIGHT) / 2) - (windowHeight / 2));
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}

void Draw::draw(const int &width, const int &height, 
        const int &lineHeight, const int &lineNumber, 
        const string &file) {
    
    srand(time(NULL));
    
    int hLinesNum = rand() % lineNumber;
    int wLinesNum = lineNumber - hLinesNum;
    
    int *hRandArr = (int *) malloc(hLinesNum * sizeof(int));
    int *wRandArr = (int *) malloc(wLinesNum * sizeof(int));
    
    int maxHeightVal = height - lineHeight;
    int maxWidthVal = width - lineHeight;
    
    generateRandomNumber(maxHeightVal, hLinesNum, hRandArr);
    generateRandomNumber(maxWidthVal, wLinesNum, wRandArr);
    
    //GL Start
    
    freeglutInit(width, height);
    glutCreateWindow("Lines system");
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glBegin(GL_LINES);
    
    //Draw start
    
    //Draw end
    
    glEnd();
    glFlush();
    
    glutMainLoop();
    
    //GL End
    
    free(hRandArr);
    free(wRandArr);
}

void Draw::generateRandomNumber(int &maxVal, int &num, int* array) {
    
    int iter, iterInner, randNum;
    bool flag;
    
    srand(time(NULL));
    
    for (iter = 0; iter < num; iter++) {
        array[iter] = 0;
    }
    
    for (iter = 0; iter < num; iter++) {
        do {
            flag = false;
            randNum = rand() % maxVal;
            for (iterInner = 0; iterInner < num; iterInner++) {
                if (array[iterInner] == randNum) {
                    flag = true;
                    break;
                }
            }
        } while(flag);
        array[iter] = randNum;
    }
}

void Draw::writeFile() {
    
}

Draw::~Draw() {
    
}

