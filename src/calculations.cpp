#include "calculations.h"

#include <cmath>

namespace {
const double delta = 1e-12;

double function(double x) {
    return x - std::cos(x);
}

double derivative(double (*func)(double x), double x, double dx = delta) {
    double dy = func(x + dx) - func(x);
    return dy / dx;
}
}  // namespace

namespace calculations {
// x - cos(x) = 0 --> x = cos(x); cos(x) ∈ [-1; 1] --> x ∈ [-1; 1] --> l = -1; r = 1;
double binaryCalculations(double precision) {
    double l = -1;
    double r = 1;
    double mid = 0;
    while (r - l > precision) {
        mid = (r + l) / 2;
        if (function((l + r) / 2) == 0) {
            return (l + r) / 2;
        }
        if (function(l) < 0 && function(mid) > 0) {
            r = (l + r) / 2;
        } else {
            l = (l + r) / 2;
        }
    }
    return (l + r) / 2;
}

double newtonsMethod(double precision) {
    double prev_x = 0;
    double x = 1;
    while (std::abs(x - prev_x) > precision) {
        prev_x = x;
        x = x + function(x) / -derivative(function, x);
    }
    return x;
}

// x - cos(x) = 0 --> x = cos(x)
double iterativeMethod(double delta) {
    double prev_x = 0;
    double x = 1;
    while (std::abs(prev_x - x) > delta) {
        prev_x = x;
        x = std::cos(x);
    }
    return x;
}
}  // namespace calculations
