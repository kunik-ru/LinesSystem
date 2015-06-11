#include "Draw.h"

using namespace std;

int argc;
char** argv;

Draw::Draw(int argc, char** argv) {
    this -> argc = argc;
    this -> argv = argv;
}

void Draw::freeglutInit(const int& windowWidth, const int& windowHeight) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) / 2) - (windowWidth / 2),
            (glutGet(GLUT_SCREEN_HEIGHT) / 2) - (windowHeight / 2));
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
}

void Draw::freeglutClear() {
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void Draw::freeglutDraw(float lineArray[][2], const int &lineNum) {
    
    glBegin(GL_LINES);
    
    int iter;
    
    /*
     * lineArray[iter][0] = x1 
     * lineArray[iter][1] = y1
     * lineArray[iter + 1][0] = x2
     * lineArray[iter + 1][1] = y2
     */
    
    for (iter = 0; iter < (lineNum * 2); iter += 2) {
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(lineArray[iter][0], lineArray[iter][1]);
        glVertex2f(lineArray[iter + 1][0], lineArray[iter + 1][1]);
    }
    
    glEnd();
    glFlush();
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
    
    float hLineArray[hLinesNum * 2][2];
    float wLineArray[wLinesNum * 2][2];
    
    int iter;
    
    /*
     * lineArray[iter][0] = x1 
     * lineArray[iter][1] = y1
     * lineArray[iter + 1][0] = x2
     * lineArray[iter + 1][1] = y2
     */
    
    for (iter = 0; iter < (hLinesNum * 2); iter += 2) {
        
        float pos = ((float)(hRandArr[(iter / 2)]) - ((float)height) / 2) / ((float)height);
        
        hLineArray[iter][0] = -1;
        hLineArray[iter][1] = pos;
        hLineArray[iter + 1][0] = 1;
        hLineArray[iter + 1][1] = pos;
    }
    
    for (iter = 0; iter < (wLinesNum * 2); iter += 2) {
        
        float pos = ((float)(wRandArr[(iter / 2)]) - ((float)width) / 2) / ((float)width);
        
        wLineArray[iter][0] = pos;
        wLineArray[iter][1] = -1;
        wLineArray[iter + 1][0] = pos;
        wLineArray[iter + 1][1] = 1;
    }
    
    writeFile(width, height, hRandArr, hLinesNum, wRandArr, wLinesNum, file);
    
    //GL Start
    
    freeglutInit(width, height);
    
    glutCreateWindow("Lines system");
    
    freeglutClear();
    
    freeglutDraw(hLineArray, hLinesNum);
    freeglutDraw(wLineArray, wLinesNum);
    
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

void Draw::writeFile(const int &width, const int &height,
            int *hRandArr, const int &hLinesNum,
            int *wRandArr, const int &wLinesNum,
            const string &file) {
    
    int pictureArray[1000][1000]; //2000 causes segmentation fault
    
    ofstream picture(file.c_str());
    
    picture << "P1" << endl;
    picture << width << " " << height << endl; 
    
    int iter, hIter, wIter;
    
    for (hIter = 0; hIter < 1000; hIter++) {
        for (wIter = 0; wIter < 1000; wIter++) {
            pictureArray[hIter][wIter] = 0;
        }
    }
    
    for (iter = 0; iter < hLinesNum; iter++) {
        for (wIter = 0; wIter < width; wIter++) {
            pictureArray[hRandArr[iter]][wIter] = 1;
        }
    }
    
    for (iter = 0; iter < wLinesNum; iter++) {
        for (hIter = 0; hIter < height; hIter++) {
            pictureArray[hIter][wRandArr[iter]] = 1;
        }
    }
    
    for (hIter = 0; hIter < height; hIter++) {
        for (wIter = 0; wIter < width; wIter++) {
            picture << pictureArray[hIter][wIter];
        }
        picture << endl;
    }
    
    picture.close();
}

Draw::~Draw() {
    
}

