#include "task3.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const double kEps = 1e-6;
const double kStep = 0.2;
const int kPrintPrecision = 6;
const int kColumnWidth = 15;

struct CalculationResult {
    double sin;
    int n;
};

CalculationResult CalculateTaylorSeries(double x, double eps = kEps) {
    double answer = 0;
    int n = 1;
    double lastTerm = x;
    while (std::abs(lastTerm) > eps) {
        answer += lastTerm;
        lastTerm *= x * x / (2 * n) / (2 * n + 1) * -1;
        ++n;
    }
    return {answer, n};
}
}  // namespace

void RunThirdTask() {
    std::cout << std::setw(kColumnWidth) << "x" << std::setw(kColumnWidth) << "sin(x)" << std::setw(kColumnWidth) << "Taylor" << std::setw(kColumnWidth) << "N" << std::endl;

    double x = 0;
    while (x <= 1) {
        CalculationResult taylorResult = CalculateTaylorSeries(x);
        std::cout << std::setw(kColumnWidth) << std::fixed << std::setprecision(kPrintPrecision) << x << std::setw(kColumnWidth) << std::sin(x)
                  << std::setw(kColumnWidth) << taylorResult.sin << std::setw(kColumnWidth) << taylorResult.n << std::endl;
        x += kStep;
    }
}
