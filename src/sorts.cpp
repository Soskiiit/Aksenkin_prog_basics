#include "sorts.h"

#include <algorithm>

namespace sorts {
SortResults BubbleSort(int* arr, size_t arrayLength, bool reverse) {
    int comparisons = 0;
    int swaps = 0;
    bool swapped = false;

    if (reverse) {
        for (int i = 0; i < arrayLength - 1; i++) {
            swapped = false;
            for (int j = 0; j < arrayLength - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    ++swaps;
                    swapped = true;
                }
                ++comparisons;
            }
            if (!swapped) {
                break;
            }
        }
    } else {
        for (int i = 0; i < arrayLength - 1; i++) {
            swapped = false;
            for (int j = 0; j < arrayLength - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    ++swaps;
                    swapped = true;
                }
                ++comparisons;
            }
            if (!swapped) {
                break;
            }
        }
    }

    return {comparisons, swaps};
}

SortResults SelectionSort(int* arr, size_t arrayLength, bool reverse) {
    int comparisons = 0;
    int swaps = 0;

    if (reverse) {
        for (int i = 0; i < arrayLength - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < arrayLength; ++j) {
                if (arr[j] > arr[minIndex]) {
                    minIndex = j;
                }
                ++comparisons;
            }
            if (i != minIndex) {
                std::swap(arr[i], arr[minIndex]);
                ++swaps;
            }
        }
    } else {
        for (int i = 0; i < arrayLength - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < arrayLength; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
                ++comparisons;
            }
            std::swap(arr[i], arr[minIndex]);
            ++swaps;
        }
    }

    return {comparisons, swaps};
}
}  // namespace sorts
