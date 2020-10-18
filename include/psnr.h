#pragma once
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

#include "image.h"
#include "not_compatible_size_exception.h"

class Psnr {
public:
  Psnr();

  double calculate(Image &original, Image &reference);
};