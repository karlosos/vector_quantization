#pragma once
#include <iostream>
#include <vector>

class Image {
public:
  Image();
  Image(const Image &image);
  virtual ~Image();

  unsigned char *rgbData;
  unsigned char *header;
  unsigned int imageSize;
  unsigned int headerSize;
  unsigned int width;
  unsigned int height;
  unsigned short bitsPerPixel;

  int getPixel(int row, int col);
  void setPixel(int row, int col, int value);
  void setData(std::vector<int> &vectors);
};
