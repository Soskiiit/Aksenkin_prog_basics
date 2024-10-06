#include <iomanip>
#include <iostream>

#include "calculations.h"

int main() {
    std::cout << "Результат с помощью бинарного поиска: " << "\t" << std::setprecision(12) << calculations::binaryCalculations() << std::endl;
    std::cout << "Результат с помощью метода Ньютона: " << "\t" << std::setprecision(12) << calculations::newtonsMethod() << std::endl;
    std::cout << "Результат с помощью метода итераций: " << "\t" << std::setprecision(12) << calculations::iterativeMethod() << std::endl;
    return 0;
}
