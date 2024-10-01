#include <iostream>

#include "task1.h"

namespace {
const int kStartOfSequence = 1;
const int kDivisor = 5;

long calculateSumFirstTerms(int n, int m) {
    int sumOfSeries = 0;
    for (int i = kStartOfSequence; i <= n; ++i) {
        if (i % m != 0 && i % kDivisor == 0) {
            sumOfSeries += i;
        }
    }
    return sumOfSeries;
}
}  // namespace

void RunFirstTask() {
    int n = 0;
    int m = 0;
    std::cout << "Введите числа n и m через пробел: ";
    std::cin >> n >> m;
    std::cout << calculateSumFirstTerms(n, m) << '\n';
}
