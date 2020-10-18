#pragma once
#include <vector>
#include <tuple>

#include "image.h"
#include "vectorizer.h"

using codebook_type = std::vector<std::vector<int>>; 
using vectors_type = std::vector<std::vector<int>>;

class BookcodeCreatorStrategyRandom  {
public:
    BookcodeCreatorStrategyRandom() = default;
    BookcodeCreatorStrategyRandom(int numOfPositions, int windowSize) : numOfPositions(numOfPositions), windowSize(windowSize) {};
    std::tuple<codebook_type, vectors_type> make(Image &image);
    bool isInCodebook(std::vector<std::vector<int>> &codebook, std::vector<int> &vector);

    int numOfPositions{200};
    int windowSize{2};
};