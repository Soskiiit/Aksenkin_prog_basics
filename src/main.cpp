#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

#include <iostream>

int main(int, char**) {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Введите номер задачи, чтобы запустить её\n"
                  << "1-я задача: Подсчёт суммы на [1;n] чисел кратных 5 и не кратных m\n"
                  << "2-я задача: Подсчёт по формуле\n"
                  << "3-я задача: Подсчёт синусов\n"
                  << "4-я задача: Вычисления по формуле с промежуточными результатами\n";

        int taskNumber = 1;
        std::cin >> taskNumber;
        switch (taskNumber) {
            case 1:
                try {
                    RunFirstTask();
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
            break;
            case 2:
                RunSecondTask();
            break;
            case 3:
                RunThirdTask();
            break;
            case 4:
                try {
                    RunFourthTask();
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
            break;
            default:
                std::cout << "Такой задачи нет\n";
        }
        std::cout << std::endl;
        std::cout << "Продолжить работу? (y/n)\n";
        std::cin >> continueExecution;
    }
    return 0;
}
