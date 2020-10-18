#pragma once

#include <stdexcept>

class NotCompatibleSizeException : public std::runtime_error {
public:
  NotCompatibleSizeException()
      : std::runtime_error("NotCompatibleSizeException") {}
};
