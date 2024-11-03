#pragma once

#include <cstddef>

namespace sorts {
struct SortResults {
    int comparisons;
    int swaps;
};
SortResults BubbleSort(int* array, size_t arrayLength, bool reverse = false);
SortResults SelectionSort(int* arr, size_t arrayLength, bool reverse = false);
}  // namespace sorts
