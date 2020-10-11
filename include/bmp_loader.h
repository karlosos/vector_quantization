#pragma once
#include <cstdio>
#include <iostream>
#include <string>

class BmpLoader {
public:
  BmpLoader();

  bool ReadBmp(std::string imagepath, unsigned char *&header,
               unsigned char *&rgbData, unsigned int &headerSize,
               unsigned int &imageSize);
  bool WriteBmp(std::string imagepath, unsigned char *&header,
                unsigned char *&rgbData, unsigned int &headerSize,
                unsigned int &imageSize, bool flip, bool gray);
};
