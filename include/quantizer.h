#pragma once

#include <cmath>
#include <limits>

#include "image.h"
#include "bookcode_creator_strategy.h"
#include "not_compatible_size_exception.h"

class Quantizer {
public:
    static Image quantize(Image &image, BookcodeCreatorStrategyRandom &bookcodeCreator);
private:
    Quantizer() {};
    static double distanceBetweenVectors(std::vector<int> vec1, std::vector<int> vec2);
    static int argMin(std::vector<int> distances);
    static Image imageFromVectors(std::vector<std::vector<int>> &vectors, Image &originalImage, int windowSize);
};
