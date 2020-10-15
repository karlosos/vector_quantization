#pragma once
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

#include "image.h"

class Psnr {
public:
  Psnr();

  double calculate(Image &original, Image &reference);
};

class NotCompatibleSizeException : public std::runtime_error {
public:
  NotCompatibleSizeException() : std::runtime_error("NotCompatibleSizeException") {}
};
