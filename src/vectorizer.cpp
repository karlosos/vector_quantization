#include "vectorizer.h"

std::vector<std::vector<int>> Vectorizer::vectorize(Image &image, int window_size) {
    int width = image.width;
    int height = image.height;
    bool can_image_be_divided = width % window_size == 0 && height % window_size == 0;
    if (!can_image_be_divided) {
        throw NotCompatibleSizeException();
    }

    std::vector<std::vector<int>> vectors;

    for (int i=0; i<height; i+=window_size) {
        for (int j=0; j<width; j+=window_size) {
           std::vector<int> vector;
           for (int k=0; k<window_size; k++) {
               for (int l=0; l<window_size; l++) {
                   vector.push_back(image.getPixel(i+k, j+l));
               }
           }
           vectors.push_back(vector);
        }
    }
    
    return(vectors);
};
