#include "../include/main.h"

namespace {
const int kFirstChickpoit = 3;
const int kSecondChickpoit = 5;
const int kThirdChickpoit = 10;
}  // namespace

void calculateAndPrint(double x, int n) {
    double answer = 1;
    double lastTerm = 1;
    for (int i = 1; i < n; i++) {
        lastTerm *= x * x / (2 * i) / (2 * i - 1) * -1;
        answer += lastTerm;
        if (i + 1 == kFirstChickpoit) {
            std::cout << "n = " << i + 1 << "\tresult = " << answer << std::endl;
        }
        if (i + 1 == kSecondChickpoit) {
            std::cout << "n = " << i + 1 << "\tresult = " << answer << std::endl;
        }
        if (i + 1 == kThirdChickpoit) {
            std::cout << "n = " << i + 1 << "\tresult = " << answer << std::endl;
        }
    }
    if (n != kFirstChickpoit && n != kSecondChickpoit && n != kThirdChickpoit) {
        std::cout << "n = " << n << "\tresult = " << answer << std::endl;
    }
}

void runFourthTask() {
    double x = 0;
    int n = 0;
    std::cout << "Введите числа x и n через пробел: ";
    std::cin >> x >> n;
    calculateAndPrint(x, n);
}
