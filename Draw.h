#ifndef DRAW_H
#define	DRAW_H

#ifndef LINES_SYSTEM_INCLUSIONS
#define LINES_SYSTEM_INCLUSIONS

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

#endif

#include <ctime>

#include <GL/freeglut.h>

class Draw {
public:
    Draw();
    void draw(const int &width, const int &height,
            const int &lineHeight, const int &lineNumber,
            const std::string &file);
    virtual ~Draw();
private:
    void freeglutInit(const int &windowWidth, const int &windowHeight);
    void generateRandomNumber(int &maxVal, int &num, int* array);
    void writeFile();
};

#endif

