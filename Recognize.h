#ifndef RECOGNIZE_H
#define	RECOGNIZE_H

#ifndef LINES_SYSTEM_INCLUSIONS
#define LINES_SYSTEM_INCLUSIONS

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#endif

class Recognize {
public:
    Recognize();
    void recognize(const std::string &file, const int &lineHeight);
    virtual ~Recognize();
private:
    void readFile(const std::string &file, int &width, int &height, int pictureArray[][1000]);
};

#endif

