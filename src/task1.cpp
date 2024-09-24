#include "../include/main.h"

namespace {
const int kStartOfSequence = 1;
const int kMustDivide = 5;
}  // namespace

long calculateSumFirstTerms(int n, int m) {
    long sumOfSeries = 0;
    for (int i = kStartOfSequence; i <= n; i++) {
        if (i % m != 0 && i % kMustDivide == 0) {
            sumOfSeries += i;
        }
    }
    return sumOfSeries;
}

void runFirstTask() {
    int n = 0;
    int m = 0;
    std::cout << "Введите числа n и m через пробел: ";
    std::cin >> n >> m;
    std::cout << calculateSumFirstTerms(n, m) << '\n';
}
