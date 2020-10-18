#include "vectorizer.h"

std::vector<std::vector<int>> Vectorizer::vectorize(Image &image, int window_size) {
    std::cout << "We're inside vectorizer" << std::endl;
    int width = image.width;
    int height = image.height;
    bool can_image_be_divided = width % window_size == 0 && height % window_size == 0;
    if (!can_image_be_divided) {
        throw NotCompatibleSizeException();
    }

    std::vector<std::vector<int>> vectors;

    for (int i=0; i<height; i+=window_size) {
        for (int j=0; j<width; j+=window_size) {
           std::vector<int> vector = {image.getPixel(i, j), image.getPixel(i, j+1), image.getPixel(i+1, j), image.getPixel(i+1, j+1)};
           vectors.push_back(vector);
        }
    }
    
    return(vectors);
};
