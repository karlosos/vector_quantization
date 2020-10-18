#include "bookcode_creator_strategy.h"

#include <chrono>
#include <random>

std::tuple<codebook_type, vectors_type>
BookcodeCreatorStrategyRandom::make(Image &image) {
  auto vectors = Vectorizer::vectorize(image, windowSize);

  codebook_type codebook;

  std::random_device os_seed;
  const uint_least32_t seed = os_seed();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<uint_least32_t> distribute(0,
                                                           vectors.size() - 1);
  while (codebook.size() < numOfPositions) {
    int index = distribute(generator);
    if (!isInCodebook(codebook, vectors.at(index))) {
      codebook.push_back(vectors.at(index));
    }
  }

  return std::make_tuple(codebook, vectors);
}

bool BookcodeCreatorStrategyRandom::isInCodebook(
    std::vector<std::vector<int>> &codebook, std::vector<int> &vector) {
  for (const auto &i : codebook) {
    if (i == vector) {
      return true;
    }
  }
  return false;
}