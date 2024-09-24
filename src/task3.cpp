#include "../include/main.h"

namespace {
const double kEps = 1e-6;
const double kStep = 0.2;
const double kStepCount = 5;
const int kPrintPrecision = 3;
const int kMargin = 9;
}  // namespace

std::pair<double, int> calculateTailorSeries(double x, double eps = kEps) {
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

void printRow(double x) {
    std::pair<double, int> tailorResult = {0, 0};
    tailorResult = calculateTailorSeries(x);
    std::cout << std::setw(kMargin) << std::fixed << std::setprecision(kPrintPrecision) << x << "\t" << std::setw(kMargin)
              << std::setprecision(kPrintPrecision) << std::sin(x) << "\t" << std::setw(kMargin) << std::setprecision(kPrintPrecision)
              << tailorResult.first << "\t" << std::setw(kMargin) << std::setprecision(kPrintPrecision) << tailorResult.second << std::endl;
}

void runThirdTask() {
    std::cout << "        x       sin(x)      Tailor          N\n";
    for (int x = 0; x <= kStepCount; x++) {
        printRow(x * kStep);
    }
}
// meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow
