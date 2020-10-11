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
  std::string path = "../img/input";
  std::vector<std::filesystem::path> files;
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    std::cout << entry.path() << std::endl;
    files.push_back(entry.path());
  }

  for (const auto &file : files) {
    unsigned char *rgbData;
    unsigned char *header;
    unsigned int imageSize;
    unsigned int headerSize;
    std::cout << "Reading the BMP file " << file << std::endl;
    std::filesystem::path input_path = "../img/input/";
    std::filesystem::path output_path = "../img/output/";
    input_path.replace_filename(file.filename());
    output_path.replace_filename(file.filename());
    bmp.ReadBmp(input_path.string(), header, rgbData, headerSize, imageSize);

    std::cout << "Writing a new BMP file " << output_path << std::endl;
    bmp.WriteBmp(output_path.string(), header, rgbData, headerSize, imageSize, false,
                 false);
    std::cout << "Freeing resources..." << std::endl;
    delete rgbData;
    delete header;
  }

  std::cout << "This application has ended its execution." << std::endl;
  return 0;
}
