#pragma once

#include <cstddef>

namespace sorts {
struct SortResults {
    int comparisons;
    int swaps;
};
SortResults bubbleSort(int* arr, size_t arrayLength, bool reverse = false);
SortResults selectionSort(int* arr, size_t arrayLength, bool reverse = false);
}  // namespace sorts
