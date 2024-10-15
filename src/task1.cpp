#include "task1.h"

#include <iostream>

namespace {
const int kStartOfSequence = 5;
const int kDivisor = 5;

int CalculateSumFirstTerms(int n, int m) {
    int sumOfSeries = 0;
    for (int i = kStartOfSequence; i <= n; i += kDivisor) {
        if (i % m != 0) {
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
    if (n < 1 || m < 1) {
        throw std::invalid_argument("Числа m и n должны быть натуральными");
    }
    if (n <= m) {
        throw std::invalid_argument("Число m должно быть меньше числа n!");
    }
    std::cout << CalculateSumFirstTerms(n, m) << '\n';
}
