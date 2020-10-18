#pragma once
#include "image.h"
#include <cstdio>
#include <iostream>
#include <string>

class BmpLoader {
public:
  BmpLoader();

  bool ReadBmp(std::string imagepath, Image &image);
  bool WriteBmp(std::string imagepath, Image &image, bool flip, bool gray);
};
