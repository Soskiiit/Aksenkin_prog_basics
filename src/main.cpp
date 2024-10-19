#include <iostream>

#include "methods.h"

namespace {
const int ignoreLength = 10'000;

enum class Method {
    NewthonsMethod = 1,
    BinaryMethod = 2,
    IterativeMethod = 3,
};

void selectMethodAndRun() {
    long double k = 0;
    int precision = 0;
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Решение уравнения x - k * cos(x) = 0\n";
        std::cout << "Введите k и точность (кол-во знаков после запятой): ";
        std::cin >> k >> precision;
        std::cout << "Выберите метод для решения уравнения x - " << k << " * cos(x) = 0\n";
        std::cout << "1) Метод Ньютона\n"
                  << "2) Метод половинного деления\n"
                  << "3) Метод итераций\n";
        int methodNumber = 0;
        std::cin >> methodNumber;
        auto method = static_cast<Method>(methodNumber);

        switch (method) {
            case Method::NewthonsMethod:
                try {
                    methods::newtons_method(k, precision);
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Method::BinaryMethod:
                try {
                    methods::binary_method(k, precision);
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Method::IterativeMethod:
                try {
                    methods::iterative_method(k, precision);
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            default:
                std::cout << "Такого метода нет\n";
        }
        std::cout << std::endl;

        std::cout << "Продолжить работу? (Y/n)\n";
        std::cin.ignore(ignoreLength, '\n');
        if (!(std::cin.peek() != '\n' && std::cin >> continueExecution)) {
            continueExecution = 'y';
        }
    }
}
}  // namespace

int main(int, char**) {
    selectMethodAndRun();
    return 0;
}
