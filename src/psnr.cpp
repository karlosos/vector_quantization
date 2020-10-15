#include "psnr.h"

Psnr::Psnr(){

};

double Psnr::calculate(Image &original, Image &reference) {
  if (original.width != reference.width || original.height != reference.height) {
    std::cout << "Psnr::calculate: image sizes are not the same" << std::endl;
    std::cout << "Original: " << original.width << " " << original.height << std::endl;
    std::cout << "Reference: " << reference.width << " " << reference.height << std::endl;
    return 0.0;
  }

  double mse = 0.0;
  for (int i = 0; i < original.height; i++) {
    for (int j = 0; j < original.width; j++) {
      int diff = original.getPixel(i, j) - reference.getPixel(i, j);
      mse += double(diff) * double(diff);
    }
  }
  mse = mse / (original.width * original.height);

  double nominator = 255 * 255;
  double result = 10.0 * std::log10(nominator/mse);
  return result;
}
