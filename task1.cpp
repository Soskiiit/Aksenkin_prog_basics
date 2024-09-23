#include <iostream>

namespace {
const int kStartOfSequence = 1;
const int kMustDivide = 5;
}

long calculate(int n, int m) {
    long sumOfSeries = 0;
    for (int i = kStartOfSequence; i <= n; i++) {
        if (i % m != 0 && i % kMustDivide == 0) {
            sumOfSeries += i;
        }
    }
    return sumOfSeries;
}

int main(int, char**) {
    int n = 0;
    int m = 0;
    char isWorks = 'y';
    while (isWorks == 'y') {
        std::cout << "Введите числа n и m через пробел: ";
        std::cin >> n >> m;
        std::cout << calculate(n, m) << '\n';
        std::cout << "Продолжаем работу? (y/n) ";
        std::cin >> isWorks;
    }
    return 0;
}
