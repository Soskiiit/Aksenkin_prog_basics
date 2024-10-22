#include "EquationSolving.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const double initialX = 0.7;
const int maxIterations = 10'000;
const double decimalBase = 10;

[[nodiscard]] double CalculateFunction(double x, double k) {
    return x - k * std::cos(x);
}

[[nodiscard]] double CalculateFunctionsDerivative(double x, double k) {
    return 1 + k * std::sin(x);
}
}  // namespace

namespace EquationSolving {
EquationResult HalfDivisionMethodCalculate(double k, double accuracy, double leftBoundary, double rightBoundary) {
    if (leftBoundary >= rightBoundary) {
        return EquationResult{.root = NAN};
    }

    if (CalculateFunction(leftBoundary, k) * CalculateFunction(rightBoundary, k) > 0) {
        return EquationResult{.root = NAN};
    }

    double mid = 0;
    int iterations = 0;

    while (rightBoundary - leftBoundary > std::abs(accuracy)) {
        mid = (rightBoundary + leftBoundary) / 2;
        ++iterations;
        if (CalculateFunction(leftBoundary, k) < 0 && CalculateFunction(mid, k) > 0) {
            rightBoundary = mid;
        } else {
            leftBoundary = mid;
        }
    }

    if (std::abs(CalculateFunction(mid, k)) > std::abs(accuracy * k)) {
        return {.root = NAN};
    }
    return {mid, iterations};
}

EquationResult NewtonsMethodCalculate(double k, double accuracy) {
    int iterations = 0;
    double previousX = 0;
    double x = initialX;

    while (std::abs(x - previousX) > accuracy && iterations < maxIterations) {
        previousX = x;
        x += CalculateFunction(x, k) / -CalculateFunctionsDerivative(x, k);
        ++iterations;
    }

    return {x, iterations};
}

EquationResult IterativeMethodCalculate(double k, double accuracy) {
    int iterations = 0;
    double previousX = 0;
    double x = initialX;

    while (std::abs(previousX - x) > accuracy) {
        previousX = x;
        x = k * std::cos(x);
        ++iterations;
        if (iterations == maxIterations) {
            return {NAN, 0};
        }
    }

    return {x, iterations};
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

    double maxDerivative = k + 1;
    double accuracy = std::pow(decimalBase, -precision) * maxDerivative;
    EquationResult binaryResult = HalfDivisionMethodCalculate(k, accuracy, leftBoundary, rightBoundary);

    if (std::isnan(binaryResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::setprecision(precision) << binaryResult.root << " число итераций: " << binaryResult.iterations << std::endl;
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

    double accuracy = std::pow(decimalBase, -precision);
    EquationResult iterativeResult = IterativeMethodCalculate(k, accuracy);

    if (std::isnan(iterativeResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::setprecision(precision) << iterativeResult.root << " число итераций: " << iterativeResult.iterations
                  << std::endl;
    }
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

    double accuracy = std::pow(decimalBase, -precision);
    EquationResult newthonsResult = NewtonsMethodCalculate(k, accuracy);

    if (std::isnan(newthonsResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::setprecision(precision) << newthonsResult.root << " число итераций: " << newthonsResult.iterations
                  << std::endl;
    }
}

void SelectMethodAndRun(EquationMethod method) {
    switch (method) {
        case EquationMethod::Newtons:
            try {
                RunNewtonsMethod();
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case EquationMethod::BinaryMethod:
            try {
                RunHalfDivisionMethod();
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case EquationMethod::IterativeMethod:
            try {
                RunIterationMethod();
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        default:
            std::cout << "Такого метода нет\n";
    }
}

void Menu() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Выберите метод для решения уравнения x - k * cos(x) = 0\n";
        std::cout << "1) Метод Ньютона\n"
                  << "2) Метод половинного деления\n"
                  << "3) Метод итераций\n";
        int method = 0;

        std::cin >> method;
        SelectMethodAndRun(static_cast<EquationMethod>(method));
        std::cout << std::endl;

        std::cout << "Продолжить работу? (y/n)\n";
        std::cin >> continueExecution;
    }
}
}  // namespace methods
