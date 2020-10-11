#pragma once
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

class BMP {
    public:

    BMP();

    bool ReadBMP(string imagepath, unsigned char *&header, unsigned char *&rgbData, unsigned int &headerSize, unsigned int &imageSize);
    bool WriteBMP(string imagepath, unsigned char *&header, unsigned char *&rgbData, unsigned int &headerSize, unsigned int &imageSize, bool flip, bool gray);
};