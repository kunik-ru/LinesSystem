#ifndef DRAW_H
#define	DRAW_H

#ifndef LINES_SYSTEM_INCLUSIONS
#define LINES_SYSTEM_INCLUSIONS

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#endif

#include <ctime>

#include <GL/freeglut.h>

class Draw {
public:
    Draw(int argc, char** argv);
    void draw(const int &width, const int &height,
            const int &lineHeight, const int &lineNumber,
            const std::string &file);
    virtual ~Draw();
private:
    int argc;
    char** argv;
    void freeglutInit(const int &windowWidth, const int &windowHeight);
    void freeglutClear();
    void freeglutDraw(float lineArray[][2], const int &lineNum);
    void generateRandomNumber(int &maxVal, int &num, int* array);
    void writeFile(const int &width, const int &height,
            int *hRandArr, const int &hLinesNum,
            int *wRandArr, const int &wLinesNum,
            const std::string &file);
};

#endif

