#include "benchmark.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "sorts.h"
#include "utils.h"

namespace {
const size_t kMinArraySize = 0;
const size_t kStaticArrayLength = 8;
const int kColumnWidth = 20;

void PrintSortResults(int comparisons, int swaps) {
    std::cout << "Количество сравнений: " << comparisons << std::endl;
    std::cout << "Количество перестановок: " << swaps << std::endl;

    std::cout << std::endl;
}

void ExecuteDynamicArraySort() {
    int comparisons = 0;
    int swaps = 0;

    size_t arraySize = 0;

    std::cout << "Введите размер динамического массива: ";
    std::cin >> arraySize;

    if (arraySize == kMinArraySize) {
        std::cout << "Введен неверный размер динамического массива." << std::endl;
        return;
    }

    int* arraySelectionSort = new int[arraySize];

    utils::FillArrayWithRandomValues(arraySelectionSort, arraySize);

    int* arrayBubbleSort = new int[arraySize];

    std::copy_n(arraySelectionSort, arraySize, arrayBubbleSort);

    std::cout << "Сортировка массива при количестве элементов " << arraySize << ":" << std::endl;
    std::cout << "                               Сравнения        Перестановки\n";
    auto selectionSortStats = sorts::SelectionSort(arraySelectionSort, arraySize);
    comparisons = selectionSortStats.comparisons;
    swaps = selectionSortStats.swaps;
    std::cout << "Сортировка выбором  " << std::setw(kColumnWidth) << comparisons << std::setw(kColumnWidth) << swaps << std::endl;

    auto bubbleSortStats = sorts::BubbleSort(arrayBubbleSort, arraySize);
    comparisons = bubbleSortStats.comparisons;
    swaps = bubbleSortStats.swaps;
    std::cout << "Сортировка пузырьком" << std::setw(kColumnWidth) << comparisons << std::setw(kColumnWidth) << swaps << std::endl;
    std::cout << std::endl;

    delete[] arrayBubbleSort;
    delete[] arraySelectionSort;
}

void ExecuteStaticArraySort() {
    int arraySelectionSort[kStaticArrayLength];
    utils::FillArrayWithRandomValues(arraySelectionSort, kStaticArrayLength);

    int comparisons = 0;
    int swaps = 0;

    std::cout << "Исходный статический массив: ";
    utils::PrintArray(arraySelectionSort, kStaticArrayLength);
    std::cout << std::endl;

    int arrayBubbleSort[kStaticArrayLength];

    std::copy_n(arraySelectionSort, kStaticArrayLength, arrayBubbleSort);
    auto sortResult = sorts::SelectionSort(arraySelectionSort, kStaticArrayLength);
    comparisons = sortResult.comparisons;
    swaps = sortResult.swaps;

    std::cout << "Сортировка выбором по возрастанию: ";
    utils::PrintArray(arraySelectionSort, kStaticArrayLength);
    PrintSortResults(comparisons, swaps);

    sortResult = sorts::SelectionSort(arraySelectionSort, kStaticArrayLength);
    comparisons = sortResult.comparisons;
    swaps = sortResult.swaps;

    std::cout << "Повторная сортировка выбором по возрастанию: ";
    utils::PrintArray(arraySelectionSort, kStaticArrayLength);
    PrintSortResults(comparisons, swaps);

    sortResult = sorts::SelectionSort(arraySelectionSort, kStaticArrayLength, true);
    comparisons = sortResult.comparisons;
    swaps = sortResult.swaps;

    std::cout << "Сортировка выбором по убыванию: ";
    utils::PrintArray(arraySelectionSort, kStaticArrayLength);
    PrintSortResults(comparisons, swaps);

    std::cout << "-------------------------------------------------\n\n";

    sortResult = sorts::BubbleSort(arrayBubbleSort, kStaticArrayLength);
    comparisons = sortResult.comparisons;
    swaps = sortResult.swaps;

    std::cout << "Сортировка пузырьком по возрастанию: ";
    utils::PrintArray(arrayBubbleSort, kStaticArrayLength);
    PrintSortResults(comparisons, swaps);

    sortResult = sorts::BubbleSort(arrayBubbleSort, kStaticArrayLength);
    comparisons = sortResult.comparisons;
    swaps = sortResult.swaps;

    std::cout << "Повторная сортировка пузырьком по возрастанию: ";
    utils::PrintArray(arrayBubbleSort, kStaticArrayLength);
    PrintSortResults(comparisons, swaps);

    sortResult = sorts::BubbleSort(arrayBubbleSort, kStaticArrayLength, true);
    comparisons = sortResult.comparisons;
    swaps = sortResult.swaps;

    std::cout << "Сортировка пузырьком по убыванию: ";
    utils::PrintArray(arrayBubbleSort, kStaticArrayLength);
    PrintSortResults(comparisons, swaps);

    std::cout << "-------------------------------------------------\n\n";
}
}  // namespace

namespace benchmark {
void RunBenchmark() {
    int task = 0;
    std::cout << "Виды задания для сортировки массивов:\n"
              << "1. Со статическим массивом\n"
              << "2. С динамическим массивом\n"
              << "Введите номер задания: ";
    std::cin >> task;
    std::cout << std::endl;
    switch (static_cast<ArrayType>(task)) {
        case ArrayType::Static:
            ExecuteStaticArraySort();
            break;
        case ArrayType::Dynamic:
            ExecuteDynamicArraySort();
            break;
        default:
            std::cout << "Введен неверный номер метода сортировки." << std::endl;
            break;
    }
}

void ExecuteApplication() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        RunBenchmark();
        std::cout << "Продолжить работу? (y/n)" << std::endl;
        std::cin >> continueExecution;
    }
}
}  // namespace benchmark
