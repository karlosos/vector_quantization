#include "image.h"

Image::Image() {

}

Image::~Image() {
    std::cout << "Freeing image resources" << std::endl;
    delete this->rgbData;
    delete this->header;
}
