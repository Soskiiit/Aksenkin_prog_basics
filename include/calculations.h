#pragma once

namespace calculations {
    const double eps = 1e-12;

    double binaryCalculations(double precision=eps);
    double newtonsMethod (double precision=eps);
    double iterativeMethod(double delta=eps);
}
