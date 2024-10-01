#include <iostream>

#include "task4.h"

namespace {
const int kFirstCheckpoint = 3;
const int kSecondCheckpoint = 5;
const int kThirdCheckpoint = 10;


void CalculateAndPrint(double x, int n) {
    double answer = 1;
    double lastTerm = 1;
    for (int i = 1; i < n; ++i) {
        lastTerm *= x * x / (2 * i) / (2 * i - 1) * -1;
        answer += lastTerm;
        if (i + 1 == kFirstCheckpoint || i + 1 == kSecondCheckpoint || i + 1 == kThirdCheckpoint) {
            std::cout << "n = " << i + 1 << "\tresult = " << answer << std::endl;
        }
    }
    std::cout << "Final result = " << answer << std::endl;
}
}  // namespace

void RunFourthTask() {
    double x = 0;
    int n = 0;
    std::cout << "Введите числа x и n через пробел: ";
    std::cin >> x >> n;
    CalculateAndPrint(x, n);
}
