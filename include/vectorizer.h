#pragma once
#include <iostream>
#include <vector>

#include "image.h"
#include "not_compatible_size_exception.h"

class Vectorizer {
public:
  static std::vector<std::vector<int>> vectorize(Image &image, int window_size);

private:
  Vectorizer();
};
