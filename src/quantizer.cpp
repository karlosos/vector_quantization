#include "quantizer.h"


Image Quantizer::quantize(Image &image, BookcodeCreatorStrategyRandom &bookcodeCreator) {
    auto [bookcode, vectors] = bookcodeCreator.make(image);
    std::vector<std::vector<int>> outputVectors;
    for (const auto &vector : vectors) {
        std::vector<int> distances;
        for (const auto &bookcodeVector : bookcode) {
            double distance = distanceBetweenVectors(bookcodeVector, vector);
            distances.push_back(distance);
        }
        int nearestBookcodeVector = argMin(distances);
        outputVectors.push_back(bookcode.at(nearestBookcodeVector));
    }

    Image outputImage = imageFromVectors(outputVectors, image, bookcodeCreator.windowSize);
    return outputImage;
}

double Quantizer::distanceBetweenVectors(std::vector<int> vec1, std::vector<int> vec2) {
    double sum;
    if (vec1.size() != vec2.size()) {
        throw NotCompatibleSizeException();
    }

    for (int i=0; i<vec1.size(); i++) {
        sum += std::pow(vec1.at(i) - vec2.at(i), 2);
    }

    return std::sqrt(sum);
}

int Quantizer::argMin(std::vector<int> distances) {
    double min = std::numeric_limits<double>::max();
    int minIndex = -1;

    for (int i=0; i<distances.size(); i++) {
        if (distances.at(i) < min) {
            min = distances.at(i);
            minIndex = i;
        }
    }
    return minIndex;
}

Image Quantizer::imageFromVectors(std::vector<std::vector<int>> &vectors, Image &originalImage, int windowSize) {
    std::cout << "Image from vectors" << std::endl;
    int width = originalImage.width;
    int height = originalImage.height;

    Image outputImage = Image(originalImage);
    std::vector<int> flat_image;

    // TODO: image to flat
    int vectorsPerWidth = width/windowSize;
    int vectorsPerHeight = height/windowSize;
    for (int i=0; i<vectorsPerHeight; i++) {
        for (int j=0; j<vectorsPerWidth; j++) {
            for (int k=0; k<windowSize; k++) {
                const auto vector = vectors.at(i*vectorsPerWidth + j);
                for (int l=0; l<windowSize; l++) {
                    flat_image.push_back(vector.at(k*windowSize+l));
                }
            }
        }
    }

    outputImage.setData(flat_image);
    return outputImage;
}
