#include "Recognize.h"

using namespace std;

Recognize::Recognize() {
    
}

void Recognize::recognize(const string &file, const int &lineHeight) {
    int pictureArray[1000][1000];
    
    int width, height;
    
    readFile(file, width, height, pictureArray);
    
    int hIter, wIter, hCounter = 0, wCounter = 0;
    
    for (hIter = 0; hIter < height; hIter++) {
        if (pictureArray[hIter][0] == 1) {
            bool flag = true;
            for (wIter = 1; wIter < width; wIter++) {
                if (pictureArray[hIter][wIter] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Horizontal line on " << hIter << endl;
                hCounter++;
            }
        }
    }
    
    for (wIter = 0; wIter < width; wIter++) {
        if (pictureArray[0][wIter] == 1) {
            bool flag = true;
            for (hIter = 1; hIter < height; hIter++) {
                if (pictureArray[hIter][wIter] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Vertical line on " << wIter << endl;
                wCounter++;
            }
        }
    }
    
    cout << "Total horizontal lines = " << hCounter << endl;
    cout << "Total vertical lines = " << wCounter << endl;
    cout << "Total lines = " << (hCounter + wCounter) << endl;
}

void Recognize::readFile(const string &file, int &width, int &height, int pictureArray[][1000]) {
    
    ifstream picture(file.c_str());
    char line[1000];
    
    if (picture.good()) {
        picture.getline(line, 1000);
        if (line[0] == 'P' && line[1] == '1') {
            picture.getline(line, 20);
            int recognizedWidth = atoi(strtok(line, " "));
            int recognizedHeight = atoi(strtok(NULL, " "));
            
            width = recognizedWidth;
            height = recognizedHeight;
            
            int hIter, wIter;
            
            for (hIter = 0; hIter < recognizedHeight; hIter++) {
                picture.getline(line, 1000);
                for (wIter = 0; wIter < recognizedWidth; wIter++) {
                    if (line[wIter] == '1') {
                        pictureArray[hIter][wIter] = 1;
                    }
                    else {
                        pictureArray[hIter][wIter] = 0;
                    }
                }
            }
        }
    }
    
    picture.close();
}

Recognize::~Recognize() {
    
}

