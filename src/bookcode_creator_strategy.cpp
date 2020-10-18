#include "bookcode_creator_strategy.h"

#include <chrono>
#include <random>

std::vector<std::vector<int>> BookcodeCreatorStrategyRandom::make(Image &image, int num_of_positions, int window_size) {
    auto vectors = Vectorizer::vectorize(image, window_size);

    std::vector<std::vector<int>> codebook;

    std::random_device os_seed;
    const uint_least32_t seed = os_seed();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<uint_least32_t> distribute(0, vectors.size()-1);
    while (codebook.size() < num_of_positions) {
        int index = distribute(generator);
        if (!isInCodebook(codebook, vectors.at(index))) {
            codebook.push_back(vectors.at(index));
        }
    }

    return codebook;
}

bool BookcodeCreatorStrategyRandom::isInCodebook(std::vector<std::vector<int>> &codebook, std::vector<int> &vector) {
    for (const auto& i: codebook) {
        if (i == vector) {
            return true;
        }
    }
    return false;
}