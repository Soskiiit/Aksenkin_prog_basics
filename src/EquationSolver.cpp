#include "EquationSolver.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const double kInitialX = 0.7;
const int kMaxIterations = 10'000;
const double kDecimalBase = 10;

[[nodiscard]] double CalculateFunction(double x, double k) {
    return x - k * std::cos(x);
}

[[nodiscard]] double CalculateFunctionsDerivative(double x, double k) {
    return 1 + k * std::sin(x);
}
}  // namespace

namespace EquationSolver {
EquationResult CalculateNewtonsMethod(double k, double accuracy) {
    int iterations = 0;
    double previousX = 0;
    double x = kInitialX;

    while (std::abs(x - previousX) > accuracy && iterations < kMaxIterations) {
        previousX = x;
        x -= CalculateFunction(x, k) / CalculateFunctionsDerivative(x, k);
        ++iterations;
    }

    return {.root = x, .iterations = iterations};
}

EquationResult CalculateHalfDivisionMethod(double k, double accuracy, double leftBoundary, double rightBoundary) {
    if (leftBoundary >= rightBoundary) {
        return {.root = NAN};
    }

    if (CalculateFunction(leftBoundary, k) * CalculateFunction(rightBoundary, k) > 0) {
        return {.root = NAN};
    }

    double mid = 0;
    int iterations = 0;

    while (rightBoundary - leftBoundary > accuracy) {
        mid = (rightBoundary + leftBoundary) / 2;
        ++iterations;
        if (CalculateFunction(leftBoundary, k) < 0.0 && CalculateFunction(mid, k) > 0.0) {
            rightBoundary = mid;
        } else {
            leftBoundary = mid;
        }
    }

    return {.root = mid, .iterations = iterations};
}

EquationResult CalculateIterativeMethod(double k, double accuracy) {
    int iterations = 0;
    double previousX = 0;
    double x = kInitialX;

    while (std::abs(x - previousX) > accuracy && iterations < kMaxIterations) {
        previousX = x;
        x = k * std::cos(x);
        ++iterations;
    }
    if (std::abs(x - previousX) > accuracy) {
        return {.root = NAN};
    }
    return {.root = x, .iterations = iterations};
}

void RunNewtonsMethod() {
    int k = 0;
    int precision = 0;
    std::cout << "Решение уравнения x - k * cos(x) = 0\n";
    std::cout << "Введите k и точность (кол-во знаков после запятой): ";
    std::cin >> k >> precision;

    if (precision < 1) {
        throw std::invalid_argument("Точность не может быть меньше 1");
    }

    double accuracy = std::pow(kDecimalBase, -precision);
    EquationResult newthonsResult = CalculateNewtonsMethod(k, accuracy);

    if (std::isnan(newthonsResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::setprecision(precision) << newthonsResult.root << " число итераций: " << newthonsResult.iterations
                  << std::endl;
    }
}

void RunHalfDivisionMethod() {
    int k = 0;
    int precision = 0;
    std::cout << "Решение уравнения x - k * cos(x) = 0\n";
    std::cout << "Введите k и точность (кол-во знаков после запятой): ";
    std::cin >> k >> precision;

    if (precision < 1) {
        throw std::invalid_argument("Точность не может быть меньше 1");
    }

    double leftBoundary = 0;
    double rightBoundary = 0;
    std::cout << "Введите левую и правую границы: ";

    std::cin >> leftBoundary >> rightBoundary;
    if (leftBoundary > rightBoundary) {
        throw std::invalid_argument("Правая граница не может быть меньше левой");
    }

    double accuracy = std::pow(kDecimalBase, -precision);
    EquationResult binaryResult = CalculateHalfDivisionMethod(k, accuracy, leftBoundary, rightBoundary);

    if (std::isnan(binaryResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::fixed << std::setprecision(precision) << binaryResult.root << " число итераций: " << binaryResult.iterations
                  << std::endl;
    }
}

void RunIterationMethod() {
    int k = 0;
    int precision = 0;
    std::cout << "Решение уравнения x - k * cos(x) = 0\n";
    std::cout << "Введите k и точность (кол-во знаков после запятой): ";
    std::cin >> k >> precision;

    if (precision < 1) {
        throw std::invalid_argument("Точность не может быть меньше 1");
    }

    double accuracy = std::pow(kDecimalBase, -precision);
    EquationResult iterativeResult = CalculateIterativeMethod(k, accuracy);

    if (std::isnan(iterativeResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::setprecision(precision) << iterativeResult.root << " число итераций: " << iterativeResult.iterations
                  << std::endl;
    }
}

void SelectMethod(EquationMethod method) {
    try {
        switch (method) {
            case EquationMethod::Newtons:
                RunNewtonsMethod();
                break;
            case EquationMethod::HalfDivision:
                RunHalfDivisionMethod();
                break;
            case EquationMethod::Iterative:
                RunIterationMethod();
                break;
            default:
                std::cout << "Такого метода нет\n";
                break;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

void ExecuteApplication() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Выберите метод для решения уравнения x - k * cos(x) = 0\n";
        std::cout << "1) Метод Ньютона\n"
                  << "2) Метод половинного деления\n"
                  << "3) Метод итераций\n";
        int method = 0;

        std::cin >> method;
        SelectMethod(static_cast<EquationMethod>(method));
        std::cout << std::endl;

        std::cout << "Продолжить работу? (y/n)\n";
        std::cin >> continueExecution;
    }
}
}  // namespace EquationSolver
