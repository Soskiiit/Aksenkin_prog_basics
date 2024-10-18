#include "methods.h"

#include <iomanip>
#include <iostream>
#include <valarray>

#include "calculations.h"

namespace {
const long double defaultL = -1.2;
const long double defaultR = 3;
const int ignoreLength = 10'000;
const long double numericBase = 10;
}  // namespace

namespace methods {
void binary_method(long double k, int precision) {
    long double l = 0;
    long double r = 0;
    std::cout << "Введите левую и правую границы (оставьте пустым для значений по умолчанию): ";

    std::cin.ignore(ignoreLength, '\n');
    if (!(std::cin.peek() != '\n' && std::cin >> l >> r)) {
        l = defaultL;
        r = defaultR;
    }
    long double maxDerivative = k + 1;
    long double accuracy = std::pow(numericBase, -precision) * maxDerivative;
    result binaryResult = calculations::binaryCalculations(l, r, k, accuracy);
    std::cout << "Решение: " << std::setprecision(precision) << binaryResult.answer << " число итераций: " << binaryResult.n << std::endl;
}

void iterative_method(long double k, int precision) {
    long double accuracy = std::pow(numericBase, -precision);
    result iterativeResult = calculations::iterativeMethod(k, accuracy);
    std::cout << "Решение: " << std::setprecision(precision) << iterativeResult.answer << " число итераций: " << iterativeResult.n << std::endl;
}

void newtons_method(long double k, int precision) {
    long double accuracy = std::pow(numericBase, -precision);
    result newthonsResult = calculations::newtonsMethod(k, accuracy);
    std::cout << "Решение: " << std::setprecision(precision) << newthonsResult.answer << " число итераций: " << newthonsResult.n << std::endl;
}
}  // namespace methods
