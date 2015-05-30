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

class Draw {
public:
    Draw();
    void draw(const int &width, const int &height,
            const int &top, const int &left,
            const int &lineHeight, const int &lineNumber,
            const std::string &file);
    virtual ~Draw();
private:
    inline int generateRandomNumber(int &maxVal, int &num, int* &array);
    void writeFile();
};

#endif

