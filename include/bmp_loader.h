#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include "image.h"

class BmpLoader {
public:
  BmpLoader();

  bool ReadBmp(std::string imagepath, Image &image);
  bool WriteBmp(std::string imagepath, Image &image, bool flip, bool gray);
};
