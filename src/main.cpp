#include <iostream>

#include "benchmark.h"

int main(int, char**) {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        benchmark::RunBenchmark();
        std::cout << "Продолжить работу? (y/n)" << std::endl;
        std::cin >> continueExecution;
    }
    return 0;
}
