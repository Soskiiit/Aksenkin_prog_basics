#include "task4.h"

#include <iostream>

namespace {
const int kFirstCheckpoint = 3;
const int kSecondCheckpoint = 5;
const int kThirdCheckpoint = 10;

void CalculateAndPrint(double x, int n) {
    double answer = 1;
    double lastTerm = 1;
    for (int i = 1; i <= n; ++i) {
        lastTerm *= x * x / (2 * i) / (2 * i - 1) * -1;
        answer += lastTerm;
        if (i == kFirstCheckpoint || i == kSecondCheckpoint || i == kThirdCheckpoint) {
            std::cout << "n = " << i << "\tрезультат = " << answer << std::endl;
        }
    }
    std::cout << "Итоговый результат = " << answer << std::endl;
}
}  // namespace

void RunFourthTask() {
    double x = 0;
    int n = 0;
    std::cout << "Введите числа x и n через пробел: ";
    std::cin >> x >> n;
    if (n < 1) {
        throw std::invalid_argument("Число n должно быть натуральным!");
    }
    CalculateAndPrint(x, n);
}
