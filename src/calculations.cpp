#include "calculations.h"

#include <cmath>
#include <iostream>

namespace {
const int maxIterations = 10'000;
const long double initialX = 0.7;

[[nodiscard]] long double function(long double x, long double k) {
    return x - k * std::cos(x);
}

[[nodiscard]] long double calculateDerivative(long double x, long double k) {
    return 1 + k * std::sin(x);
}
}  // namespace

namespace calculations {
result binaryCalculations(long double l, long double r, long double k, long double accuracy) {
    long double mid = 0;
    int n = 0;
    while (std::abs(r - l) > std::abs(accuracy)) {
        mid = (r + l) / 2;
        ++n;
        if (function(l, k) < 0 && function(mid, k) > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (std::abs(function(mid, k)) > std::abs(accuracy * k)) {
        throw std::runtime_error("В заданном диапазоне нет решений");
    }
    return {mid, n};
}

result newtonsMethod(long double k, long double accuracy) {
    int n = 0;
    long double prev_x = 0;
    long double x = initialX;
    while (std::abs(x - prev_x) > accuracy) {
        prev_x = x;
        long double derivative = calculateDerivative(x, k);
        long double y = function(x, k);
        x += y / -derivative;
        ++n;
        if (n == maxIterations) {
            throw std::runtime_error("Не удалось найти решение");
        }
    }
    return {x, n};
}

// x - k*cos(x) = 0 --> x = k*cos(x)
result iterativeMethod(long double k, long double accuracy) {
    int n = 0;
    long double prev_x = 0;
    long double x = initialX;
    while (std::abs(prev_x - x) > accuracy) {
        prev_x = x;
        x = k * std::cos(x);
        ++n;
        if (n == maxIterations) {
            throw std::runtime_error("Не удалось найти решение");
        }
    }
    return {x, n};
}
}  // namespace calculations
