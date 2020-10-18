#pragma once
#include <vector>

#include "image.h"
#include "vectorizer.h"

class BookcodeCreatorStrategy {
public:
    virtual ~BookcodeCreatorStrategy() {};
    virtual std::vector<std::vector<int>> make(Image &image, int num_of_positions, int window_size) = 0;
};

class BookcodeCreatorStrategyRandom {
public:
    std::vector<std::vector<int>> make(Image &image, int num_of_positions, int window_size);
    bool isInCodebook(std::vector<std::vector<int>> &codebook, std::vector<int> &vector);
};