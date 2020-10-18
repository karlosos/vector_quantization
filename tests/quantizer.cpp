#include "quantizer.h"
#include "bmp_loader.h"
#include "bookcode_creator_strategy.h"
#include "doctest.h"
#include "image.h"
#include "psnr.h"

TEST_CASE("Quantize image") {
  BmpLoader bmp;

  Image image1;
  bmp.ReadBmp("../img/input/balloon.bmp", image1);

  BookcodeCreatorStrategyRandom bookcodeCreator =
      BookcodeCreatorStrategyRandom(50, 2);
  Image image2 = Quantizer::quantize(image1, bookcodeCreator);

  Psnr psnr;
  double image_psnr = psnr.calculate(image1, image2);
  std::cout << "Image psnr: " << image_psnr << std::endl;
  CHECK((image_psnr > 18 && image_psnr < 38));
}