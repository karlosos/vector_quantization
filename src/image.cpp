#include "image.h"

Image::Image() {

}

Image::Image(const Image& image) {
  imageSize = image.imageSize;
  headerSize = image.headerSize;
  width = image.width;
  height = image.height;
  bitsPerPixel = image.bitsPerPixel;
  header = new unsigned char[image.headerSize];
  rgbData = new unsigned char[image.imageSize];

  for (int i=0; i<headerSize; i++) {
      header[i] = image.header[i];
  }

  for (int i=0; i<imageSize; i++) {
      rgbData[i] = image.rgbData[i];
  }
}

Image::~Image() {
    std::cout << "Freeing image resources" << std::endl;
    delete this->rgbData;
    delete this->header;
}

int Image::getPixel(int row, int col) {
    int position = -(row - this->height+1) * this->width + col;
    return int(this->rgbData[position]);
}

void Image::setPixel(int row, int col, int value) {
    int position = -(row - this->height+1) * this->width + col;
    this->rgbData[position] = static_cast<unsigned char>(value);
}

void Image::setData(std::vector<int> &vector) {
    std::cout << "set data" << std::endl;
    int index = 0;
    for (const auto &element : vector) {
        this->rgbData[index] = static_cast<unsigned char>(element);
        index++;
    }
}