#pragma once

#include <cstddef>

namespace utils {
const int kMaxRandomNumber = 99;

void fillArrayWithRandomValues(int* arr, size_t arrLength, int minNumber = 0, int maxNumber = kMaxRandomNumber);
void printArray(int* arr, size_t arrLength);
}  // namespace utils
