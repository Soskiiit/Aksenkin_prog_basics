#include "utils.h"

#include <iostream>
#include <random>

namespace utils {
void FillArrayWithRandomValues(int* arr, size_t arrLength, int minNumber, int maxNumber) {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(minNumber, maxNumber);
    for (size_t i = 0; i < arrLength; i++) {
        arr[i] = distribution(randomEngine);
    }
}

void PrintArray(int* arr, size_t arrLength) {
    for (size_t i = 0; i < arrLength; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
}  // namespace utils
