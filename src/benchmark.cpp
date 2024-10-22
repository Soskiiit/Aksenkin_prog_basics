#include "benchmark.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "sorts.h"
#include "utils.h"

namespace {
const size_t kStaticArrayLength = 8;
const int kColumnWidth = 12;

void bubbleStaticSortBenchmark(int* arr, size_t arrLength) {
    auto firstBubbleSortResults = sorts::bubbleSort(arr, arrLength);
    auto secondBubbleSortResults = sorts::bubbleSort(arr, arrLength);
    auto thirdBubbleSortResults = sorts::bubbleSort(arr, arrLength, true);

    std::cout << "          Пузырьковая сортировка\n";
    std::cout << "      Проход   Сравнений       Замен\n";
    std::cout << std::setw(kColumnWidth) << 1 << std::setw(kColumnWidth) << firstBubbleSortResults.comparisons << std::setw(kColumnWidth)
              << firstBubbleSortResults.swaps << std::endl;
    std::cout << std::setw(kColumnWidth) << 2 << std::setw(kColumnWidth) << secondBubbleSortResults.comparisons << std::setw(kColumnWidth)
              << secondBubbleSortResults.swaps << std::endl;
    std::cout << std::setw(kColumnWidth) << 3 << std::setw(kColumnWidth) << thirdBubbleSortResults.comparisons << std::setw(kColumnWidth)
              << thirdBubbleSortResults.swaps << std::endl;
    std::cout << std::endl;
}

void selectionStaticSortBenchmark(int* arr, size_t arrLength) {
    auto firstSelectionSortResults = sorts::selectionSort(arr, arrLength);
    auto secondSelectionSortResults = sorts::selectionSort(arr, arrLength);
    auto thirdSelectionSortResults = sorts::selectionSort(arr, arrLength, true);

    std::cout << "            Сортировка выбором\n";
    std::cout << "      Проход   Сравнений       Замен\n";
    std::cout << std::setw(kColumnWidth) << 1 << std::setw(kColumnWidth) << firstSelectionSortResults.comparisons << std::setw(kColumnWidth)
              << firstSelectionSortResults.swaps << std::endl;
    std::cout << std::setw(kColumnWidth) << 2 << std::setw(kColumnWidth) << secondSelectionSortResults.comparisons << std::setw(kColumnWidth)
              << secondSelectionSortResults.swaps << std::endl;
    std::cout << std::setw(kColumnWidth) << 3 << std::setw(kColumnWidth) << thirdSelectionSortResults.comparisons << std::setw(kColumnWidth)
              << thirdSelectionSortResults.swaps << std::endl;
    std::cout << std::endl;
}
}  // namespace

namespace benchmark {
void runBenchmark() {
    size_t dynamicArrLength = 0;
    std::cout << "Введите длину для динамического массива: ";
    std::cin >> dynamicArrLength;

    // static array
    int staticArr[kStaticArrayLength] = {0};
    int staticArrTemp[kStaticArrayLength] = {0};
    utils::fillArrayWithRandomValues(staticArr, kStaticArrayLength);

    std::cout << "Тесты со статическими массивами\n";
    std::cout << "Исходный массив: " << std::endl;
    utils::printArray(staticArr, kStaticArrayLength);

    std::copy_n(staticArr, kStaticArrayLength, staticArrTemp);
    bubbleStaticSortBenchmark(staticArrTemp, kStaticArrayLength);

    std::copy_n(staticArr, kStaticArrayLength, staticArrTemp);
    selectionStaticSortBenchmark(staticArrTemp, kStaticArrayLength);
    std::cout << std::endl;

    // dynamic array
    std::cout << "Тесты с динамическими массивами\n";
    int* dynamicArr = new int[dynamicArrLength];
    int* dynamicArrTemp = new int[dynamicArrLength];
    utils::fillArrayWithRandomValues(dynamicArr, dynamicArrLength);

    std::copy(dynamicArr, dynamicArr + dynamicArrLength, dynamicArrTemp);
    auto selectionSortResult = sorts::selectionSort(dynamicArr, dynamicArrLength);
    std::copy(dynamicArr, dynamicArr + dynamicArrLength, dynamicArrTemp);
    auto bubbleSortResult = sorts::bubbleSort(dynamicArr, dynamicArrLength);

    std::cout << "            Сортировка выбором\n";
    std::cout << "      Проход   Сравнений       Замен\n";
    std::cout << std::setw(kColumnWidth) << 1 << std::setw(kColumnWidth) << selectionSortResult.comparisons << std::setw(kColumnWidth)
              << selectionSortResult.swaps << std::endl;
    std::cout << std::endl;

    std::cout << "          Пузырьковая сортировка\n";
    std::cout << "      Проход   Сравнений       Замен\n";
    std::cout << std::setw(kColumnWidth) << 1 << std::setw(kColumnWidth) << bubbleSortResult.comparisons << std::setw(kColumnWidth)
              << bubbleSortResult.swaps << std::endl;
    std::cout << std::endl;

    delete[] dynamicArrTemp;
    delete[] dynamicArr;
}
}  // namespace benchmark
