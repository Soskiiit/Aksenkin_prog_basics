#pragma once

namespace {
    const double eps = 1e-12;
}

namespace calculations {
    double binaryCalculations(double precision=eps);
    double newtonsMethod (double precision=eps);
    double iterativeMethod(double delta=eps);
}
