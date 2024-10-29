#pragma once

namespace EquationSolver {
enum class EquationMethod {
    Newton = 1,
    HalfDivision = 2,
    Iterative = 3,
};

struct EquationResult {
    double root = 0;
    int iterations = 0;
};

[[nodiscard]] EquationResult CalculateNewtonsMethod(double k, double accuracy);
[[nodiscard]] EquationResult CalculateHalfDivisionMethod(double k, double accuracy, double leftBoundary, double rightBoundary);
[[nodiscard]] EquationResult CalculateIterativeMethod(double k, double accuracy);

void RunNewtonsMethod();
void RunHalfDivisionMethod();
void RunIterationMethod();

void SelectMethod(EquationMethod method);
void ExecuteApplication();
}  // namespace EquationSolver
