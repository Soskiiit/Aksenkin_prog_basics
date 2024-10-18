#pragma once

struct result {
    long double answer;
    int n;
};

namespace calculations {
    const double eps = 1e-12;

    result binaryCalculations(long double l, long double r, long double k, long double accuracy=eps);
    result newtonsMethod (long double k, long double accuracy=eps);
    result iterativeMethod(long double k, long double accuracy=eps);
}
