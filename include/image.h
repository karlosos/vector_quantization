#pragma once
#include <iostream>

class Image {
public:
  Image();
  virtual ~Image();

  unsigned char *rgbData;
  unsigned char *header;
  unsigned int imageSize;
  unsigned int headerSize;
  unsigned int width;
  unsigned int height;
  unsigned short bitsPerPixel;
};
