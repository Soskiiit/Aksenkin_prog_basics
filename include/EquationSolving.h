#pragma once

namespace EquationSolving {
enum class EquationMethod {
    Newtons = 1,
    BinaryMethod = 2,
    IterativeMethod = 3,
};

struct EquationResult {
    double root;
    int iterations;
};

[[nodiscard]] EquationResult HalfDivisionMethodCalculate(double k, double accuracy, double leftBoundary, double rightBoundary);
[[nodiscard]] EquationResult NewtonsMethodCalculate(double k, double accuracy);
[[nodiscard]] EquationResult IterativeMethodCalculate(double k, double accuracy);
void SelectMethodAndRun(EquationMethod method);
void RunHalfDivisionMethod();
void RunIterationMethod();
void RunNewtonsMethod();;
void Menu();
}  // namespace methods
