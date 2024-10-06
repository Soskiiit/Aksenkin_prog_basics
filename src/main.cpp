#include <iomanip>
#include <iostream>

#include "calculations.h"

namespace {
const int precision = 12;
}

int main() {
    std::cout << "Результат с помощью бинарного поиска: " << "\t" << std::setprecision(precision) << calculations::binaryCalculations() << std::endl;
    std::cout << "Результат с помощью метода Ньютона: " << "\t" << std::setprecision(precision) << calculations::newtonsMethod() << std::endl;
    std::cout << "Результат с помощью метода итераций: " << "\t" << std::setprecision(precision) << calculations::iterativeMethod() << std::endl;
    return 0;
}
