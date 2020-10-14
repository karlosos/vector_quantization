#include "psnr.h"

Psnr::Psnr(){

};

double Psnr::calculate(Image &original, Image &reference) {
  if (original.width != reference.width || original.height != reference.width) {
    return 0.0;
  }

  double sum = 0.0;
  for (int i = 0; i < original.height; i++) {
    for (int j = 0; j < original.width; i++) {
      int diff = original.getPixel(i, j) - reference.getPixel(i, j);
      sum += double(diff) * double(diff);
    }
  }

  double nominator = original.width * original.height * 255 * 255;
  double result = std::log10(nominator/sum);
  return result;
}
