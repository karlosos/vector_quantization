#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

#include "image.h"

class Psnr {
public:
  Psnr();

  double calculate(Image &original, Image &reference);
};
