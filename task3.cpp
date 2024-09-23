#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const double kEps = 1e-6;
const double kStep = 0.2;
}

std::pair<double, int> calculateTailorSeries(double x, double eps=kEps) {
    double answer = 0;
    int n = 1;
    double lastTerm = x;
    while (std::abs(lastTerm) > eps) {
        answer += lastTerm;
        lastTerm = lastTerm * x * x / (2 * n) / (2 * n + 1) * -1;
        n += 1;
    }
    std::pair<double, int> tailorResult = {answer, n};
    return tailorResult;
}

void printRow (double x) {
    std::pair<double, int> tailorResult = {0, 0};
    tailorResult = calculateTailorSeries(x);
    std::cout << std::setw(9) << std::setprecision(3) << x << "\t"
    << std::setw(9) << std::setprecision(3) << std::sin(x) << "\t"
    << std::setw(9) << std::setprecision(3) << tailorResult.first << "\t"
    << std::setw(9) << std::setprecision(3) << tailorResult.second << std::endl;
}

int main(int, char**) {
    std::cout << std::setw(9) << "x"
    << std::setw(13) << "sin(x)"
    << std::setw(11) << "Tailor"
    << std::setw(12) << "N" << std::endl;
    for (double x = 0; x <= 1; x += kStep) {
        printRow(x);
    }
    return 0;
}
// meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow
