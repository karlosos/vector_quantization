#include "image.h"

Image::Image() {

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
