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
#include <tuple>
#include <utility>

#include "bmp_loader.h"
#include "bookcode_creator_strategy.h"
#include "example.h"
#include "exampleConfig.h"
#include "image.h"
#include "psnr.h"
#include "quantizer.h"
#include "vectorizer.h"


void processing_all_images() {
  BmpLoader bmp = BmpLoader();

  // Find all images
  std::string path = "../img/input";
  std::vector<std::filesystem::path> files;
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    std::cout << entry.path() << std::endl;
    files.push_back(entry.path());
  }

  bool all_divided_by = true;
  int divider = 16;

  for (const auto &file : files) {
    Image image;
    std::cout << "Reading the BMP file " << file << std::endl;
    std::filesystem::path input_path = "../img/input/";
    std::filesystem::path output_path = "../img/output/";
    input_path.replace_filename(file.filename());
    output_path.replace_filename(file.filename());
    bmp.ReadBmp(input_path.string(), image);

    std::cout << "Size: ";
    std::cout << image.width << " ";
    std::cout << image.height << std::endl;
    std::cout << "Is divided by 2: ";
    bool divided_by = image.width % divider == 0 && image.width % divider == 0;
    if (!divided_by) {
      all_divided_by = false;
    }
    std::cout << divided_by << std::endl;

    std::cout << "Writing a new BMP file " << output_path << std::endl;
    std::string filename = "../img/output/out.bmp";
    bmp.WriteBmp(filename, image, false, false);
  }

  std::cout << "All images are divided by " << divider << " " << all_divided_by
            << std::endl;

  std::cout << "This application has ended its execution." << std::endl;
}

void vectorization() {
  BmpLoader bmp;

  Image image1;
  bmp.ReadBmp("../img/input/balloon.bmp", image1);

  // vectorization
  auto vectors = Vectorizer::vectorize(image1, 2);
  std::cout << "Width " << image1.width << " height:" << image1.height
            << std::endl;
  std::cout << "vectors length " << vectors.size() << std::endl;
  std::cout << "sample vector: " << std::endl;
  for (const auto &i : vectors.at(1))
    std::cout << i << ' ';
  std::cout << std::endl;
}

void bookcode() {
  BmpLoader bmp;

  Image image1;
  bmp.ReadBmp("../img/input/balloon.bmp", image1);

  // bookcode creation
  BookcodeCreatorStrategyRandom bookcode_creator;
  auto [bookcode, vectors] = bookcode_creator.make(image1);
  std::cout << "Bookcode size: " << bookcode.size() << std::endl;
  std::cout << "Bookcode sample: " << std::endl;
  for (const auto &i : bookcode.at(0)) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

void quantization() {
  BmpLoader bmp;

  Image image1;
  bmp.ReadBmp("../img/input/balloon.bmp", image1);

  BookcodeCreatorStrategyRandom bookcodeCreator =
      BookcodeCreatorStrategyRandom(50, 2);
  Image image2 = Quantizer::quantize(image1, bookcodeCreator);

  bmp.WriteBmp("../img/output/balloon_quantized.bmp", image2, false, false);

  Psnr psnr;
  std::cout << "PSNR: " << psnr.calculate(image1, image2) << std::endl;
}

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::cout << "Vector Quantization " << PROJECT_VERSION_MAJOR << "."
            << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH << "."
            << PROJECT_VERSION_TWEAK << std::endl;

  // vectorization();
  // bookcode();
  quantization();

  return 0;
}
