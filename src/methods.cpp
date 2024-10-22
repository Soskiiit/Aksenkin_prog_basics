#include "methods.h"

#include <iomanip>
#include <iostream>
#include <valarray>

namespace {
const double defaultL = -1.2;
const double defaultR = 3;
const double initialX = 0.7;

const int ignoreLength = 10'000;
const int maxIterations = 10'000;
const double decimalBase = 10;

[[nodiscard]] double CalculateFunction(double x, double k) {
    return x - k * std::cos(x);
}

[[nodiscard]] double CalculateFunctionsDerivative(double x, double k) {
    return 1 + k * std::sin(x);
}
}  // namespace

namespace methods {
[[nodiscard]] EquasionResult HalfDivisionMethodCalculate(double k, double accuracy, double leftBoundary, double rightBoundary) {
    double mid = 0;
    int n = 0;

    if (CalculateFunction(leftBoundary, k) * CalculateFunction(rightBoundary, k) > 0) {
        return EquasionResult{NAN, 0};
    }

    while (std::abs(rightBoundary - leftBoundary) > std::abs(accuracy)) {
        mid = (rightBoundary + leftBoundary) / 2;
        ++n;
        if (CalculateFunction(leftBoundary, k) < 0 && CalculateFunction(mid, k) > 0) {
            rightBoundary = mid;
        } else {
            leftBoundary = mid;
        }
    }

    if (std::abs(CalculateFunction(mid, k)) > std::abs(accuracy * k)) {
        return {NAN, 0};
    }
    return {mid, n};
}

[[nodiscard]] EquasionResult NewtonsMethodCalculate(double k, double accuracy) {
    int n = 0;
    double prev_x = 0;
    double x = initialX;

    while (std::abs(x - prev_x) > accuracy) {
        prev_x = x;
        double derivative = CalculateFunctionsDerivative(x, k);
        double y = CalculateFunction(x, k);
        x += y / -derivative;
        ++n;
        if (n == maxIterations) {
            return {NAN, 0};
        }
    }

    return {x, n};
}

// x - k*cos(x) = 0 --> x = k*cos(x)
[[nodiscard]] EquasionResult IterativeMethodCalculate(double k, double accuracy) {
    int n = 0;
    double previousX = 0;
    double x = initialX;

    while (std::abs(previousX - x) > accuracy) {
        previousX = x;
        x = k * std::cos(x);
        ++n;
        if (n == maxIterations) {
            return {NAN, 0};
        }
    }

    return {x, n};
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
    std::cout << "Введите левую и правую границы (оставьте пустым для значений по умолчанию): ";

    std::cin.ignore(ignoreLength, '\n');
    if (!(std::cin.peek() != '\n' && std::cin >> leftBoundary >> rightBoundary)) {
        leftBoundary = defaultL;
        rightBoundary = defaultR;
    }

    if (leftBoundary > rightBoundary) {
        throw std::invalid_argument("Правая граница не может быть меньше левой");
    }

    double maxDerivative = k + 1;
    double accuracy = std::pow(decimalBase, -precision) * maxDerivative;
    EquasionResult binaryResult = HalfDivisionMethodCalculate(k, accuracy, leftBoundary, rightBoundary);

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
    EquasionResult iterativeResult = IterativeMethodCalculate(k, accuracy);

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
    EquasionResult newthonsResult = NewtonsMethodCalculate(k, accuracy);

    if (std::isnan(newthonsResult.root)) {
        std::cout << "Не удалось найти решение" << std::endl;
    } else {
        std::cout << "Решение: " << std::setprecision(precision) << newthonsResult.root << " число итераций: " << newthonsResult.iterations
                  << std::endl;
    }
}

void SelectMethodAndRun() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Выберите метод для решения уравнения x - k * cos(x) = 0\n";
        std::cout << "1) Метод Ньютона\n"
                  << "2) Метод половинного деления\n"
                  << "3) Метод итераций\n";
        int method = 0;
        std::cin >> method;

        switch (static_cast<Method>(method)) {
            case Method::NewthonsMethod:
                try {
                    RunNewtonsMethod();
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Method::BinaryMethod:
                try {
                    RunHalfDivisionMethod();
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Method::IterativeMethod:
                try {
                    RunIterationMethod();
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            default:
                std::cout << "Такого метода нет\n";
        }
        std::cout << std::endl;

        std::cout << "Продолжить работу? (y/n)\n";
        std::cin.ignore(ignoreLength, '\n');
        if (!(std::cin.peek() != '\n' && std::cin >> continueExecution)) {
            continueExecution = 'y';
        }
    }
}
}  // namespace methods
