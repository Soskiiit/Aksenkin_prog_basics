#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

#include <iostream>

int main(int, char**) {
    int taskNumber = 1;
    while (taskNumber) {
        std::cout << "Введите номер задачи, чтобы запустить её или 0, чтобы выйти\n" <<
                "1-я задача: Подсчёт суммы на [1;n] чисел кратных 5 и не кратных m\n" <<
                "2-я задача: Подсчёт по формуле\n" <<
                "3-я задача: Подсчёт синусов\n" <<
                "4-я задача: Вычисления по формуле с промежуточными результатами\n";
        std::cin >> taskNumber;
        switch (taskNumber) {
            case 1:
                RunFirstTask();
                break;
            case 2:
                RunSecondTask();
                break;
            case 3:
                RunThirdTask();
                break;
            case 4:
                RunFourthTask();
                break;
            case 0:
                std::cout << "Завершение\n";
                break;
            default:
                std::cout << "Такой задачи нет\n";
        }
    }
    return 0;
}
