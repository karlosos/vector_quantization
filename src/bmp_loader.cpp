#include "bmp_loader.h"

BmpLoader::BmpLoader() {}

bool BmpLoader::ReadBmp(std::string imagepath, Image &image) {
  // BMP Header
  image.header = new unsigned char[54]; // 54-bytes Header

  // Open the file
  FILE *file = fopen(imagepath.c_str(), "rb");
  if (!file) {
    std::cerr << "Image could not be opened\n" << std::endl;
    return false;
  }

  // If it cannot read at least 54 bytes then this is not a valid BMP File
  // If the first two bytes are not "BM" respectively this is not a valid BMP
  // file

  if (fread(image.header, 1, 54, file) != 54 || image.header[0] != 'B' ||
      image.header[1] != 'M') {
    std::cerr << "This is not a valid BMP file\n" << std::endl;
    return false;
  }

  // This header locations are specified on the bitmap format specification
  // (http://www.fastgraph.com/help/bmp_header_format.html)
  image.headerSize = *(int *)&image.header[10];
  image.imageSize = *(int *)&image.header[34];
  image.width = *(int *)&image.header[18];
  image.height = *(int *)&image.header[22];
  image.bitsPerPixel = *(short *)&image.header[28];

  if (image.headerSize > 54) {
    // Header size is greater than 54 bytes, let's read the whole header.
    delete image.header;
    image.header = new unsigned char[image.headerSize];
    rewind(file);
    fread(image.header, 1, image.headerSize, file);
  } else if (image.headerSize ==
             0) // If header size was not specified within the file header.
  {
    // The BMP header has 54 bytes of that, the image should start right after
    // the header.
    image.headerSize = 54;
  }

  // Setting default values of imageSize if it was not found on the file header.
  if (image.imageSize == 0) {
    image.imageSize = image.width * image.height * (image.bitsPerPixel / 8);
  }

  // Create a buffer
  image.rgbData = new unsigned char[image.imageSize];

  // Read the actual data from the file into the buffer.
  fread(image.rgbData, 1, image.imageSize, file);

  // Everything is in memory now, the file can be closed.
  fclose(file);

  return true;
}

bool BmpLoader::WriteBmp(std::string imagepath, Image &image, bool flip = false,
                         bool gray = false) {
  unsigned char *flippedData = nullptr;
  if (flip) {
    flippedData = new unsigned char[image.imageSize];
    const short bytesPerPixel = (*(short *)&image.header[28]) / 8;
    int rgbaIndex = 0;
    int j = 0;
    for (int i = image.imageSize - 1; i >= 0; i -= bytesPerPixel) {
      for (short k = 0; k < bytesPerPixel; k++) {
        // We are reading the data backwards but we still need the RGBA values
        // on forward direction
        flippedData[j + k] = image.rgbData[i - (bytesPerPixel - k - 1)];
      }
      j += bytesPerPixel;
    }
  }
  if (gray) {
    if (flip) {
      // TODO: maybe deep copy image object?
      // following line will change data
      image.rgbData = flippedData;
    }
    const short bytesPerPixel = (*(short *)&image.header[28]) / 8;
    short gray;

    // Applying a grayscale filter
    for (int i = 0; i < image.imageSize; i += bytesPerPixel) {
      // We create a grayscale filter by giving the same value to all RGB
      // components. The given value is the average of all components
      gray =
          (image.rgbData[i] + image.rgbData[i + 1] + image.rgbData[i + 2]) / 3;
      image.rgbData[i] = gray;
      image.rgbData[i + 1] = gray;
      image.rgbData[i + 2] = gray;
    }
  }

  FILE *file;
  file = fopen(imagepath.c_str(), "wb");
  fwrite(image.header, 1, image.headerSize, file);
  fwrite(flip ? flippedData : image.rgbData, 1, image.imageSize, file);
  fclose(file);
  return true;
}
