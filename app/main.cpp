// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include <filesystem>
#include <iostream>
#include <stdlib.h>

#include "bmp_loader.h"
#include "example.h"
#include "exampleConfig.h"
#include "image.h"
#include "psnr.h"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::cout << "Vector Quantization " << PROJECT_VERSION_MAJOR << "."
            << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH << "."
            << PROJECT_VERSION_TWEAK << std::endl;

  BmpLoader bmp = BmpLoader();

  // Find all images
  // std::string path = "../img/input";
  // std::vector<std::filesystem::path> files;
  // for (const auto &entry : std::filesystem::directory_iterator(path)) {
  //   std::cout << entry.path() << std::endl;
  //   files.push_back(entry.path());
  // }

  // for (const auto &file : files) {
  //   Image image;
  //   std::cout << "Reading the BMP file " << file << std::endl;
  //   std::filesystem::path input_path = "../img/input/";
  //   std::filesystem::path output_path = "../img/output/";
  //   input_path.replace_filename(file.filename());
  //   output_path.replace_filename(file.filename());
  //   bmp.ReadBmp(input_path.string(), image);

  //   std::cout << "Pixels: " << std::endl;
  //   std::cout << image.getPixel(0, 0) << std::endl;
  //   std::cout << image.getPixel(0, 1) << std::endl;
  //   std::cout << image.getPixel(0, 2) << std::endl;

  //   std::cout << "Writing a new BMP file " << output_path << std::endl;
  //   std::string filename = "../img/output/out.bmp";
  //   bmp.WriteBmp(filename, image, false, false);
  // }

  // std::cout << "This application has ended its execution." << std::endl;

  // testing image

  Image image1;
  bmp.ReadBmp("../img/input/balloon.bmp", image1);

  Image image2;
  bmp.ReadBmp("../img/output/balloon_noise.bmp", image2);
  Psnr psnr; 

  std::cout << "PSNR: " << psnr.calculate(image1, image2) << std::endl;

  // std::cout << image.width << std::endl;
  // std::cout << image.height << std::endl;
  // std::cout << image.imageSize << std::endl;

  // std::cout << "Pixels: " << std::endl;
  // std::cout << image.getPixel(0, 0) << std::endl;
  // std::cout << image.getPixel(1, 1) << std::endl;
  // std::cout << image.getPixel(1, 2) << std::endl;

  std::string filename = "../img/output/balloon.bmp";
  bmp.WriteBmp(filename, image1, false, false);
  return 0;
}
