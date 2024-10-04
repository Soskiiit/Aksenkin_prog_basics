#include "task3.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const double kEps = 1e-6;
const double kStep = 0.2;
const double kStepCount = 5;
const int kPrintPrecision = 6;
const int kMargin = 15;

struct CalculateResult {
    double sin;
    int n;
};

CalculateResult CalculateTaylorSeries(double x, double eps = kEps) {
    double answer = 0;
    int n = 1;
    double lastTerm = x;
    while (std::abs(lastTerm) > eps) {
        answer += lastTerm;
        lastTerm = lastTerm * x * x / (2 * n) / (2 * n + 1) * -1;
        ++n;
    }
    return {answer, n};
}
}  // namespace

void RunThirdTask() {
    std::cout << std::setw(kMargin) << "x" << std::setw(kMargin) << "sin(x)" << std::setw(kMargin) << "Taylor" << std::setw(kMargin) << "N\n";
    float x = 0;
    while (x <= 1) {
        CalculateResult taylorResult{0};
        taylorResult = CalculateTaylorSeries(x * kStep);
        std::cout << std::setw(kMargin) << std::fixed << std::setprecision(kPrintPrecision) << x * kStep << std::setw(kMargin) << std::sin(x * kStep)
                  << std::setw(kMargin) << taylorResult.sin << std::setw(kMargin) << taylorResult.n << std::endl;
        x += kStep;
    }
}
