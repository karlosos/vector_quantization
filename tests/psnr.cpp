#include "psnr.h"
#include "bmp_loader.h"
#include "doctest.h"
#include "image.h"

TEST_CASE("calculate psnr for two images") {
  BmpLoader bmp = BmpLoader();

  Image image1;
  CHECK(bmp.ReadBmp("../img/input/balloon.bmp", image1));

  Image image2;
  CHECK(bmp.ReadBmp("../img/input/balloon_noise.bmp", image2));
  Psnr p;

  double image_psnr = p.calculate(image1, image2);
  CHECK((image_psnr > 50 && image_psnr < 52));
}

TEST_CASE("calculate psnr for two different images in size") {
  BmpLoader bmp = BmpLoader();

  Image image1;
  CHECK(bmp.ReadBmp("../img/input/balloon.bmp", image1));

  Image image2;
  CHECK(bmp.ReadBmp("../img/input/Aerial.bmp", image2));
  Psnr p;

  CHECK_THROWS_AS(p.calculate(image1, image2), NotCompatibleSizeException);
}
