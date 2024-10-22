#pragma once

namespace methods {
enum class Method {
    NewthonsMethod = 1,
    BinaryMethod = 2,
    IterativeMethod = 3,
};

struct EquasionResult {
    double root;
    int iterations;
};

void RunHalfDivisionMethod();
void RunIterationMethod();
void RunNewtonsMethod();
void SelectMethodAndRun();
}  // namespace methods
