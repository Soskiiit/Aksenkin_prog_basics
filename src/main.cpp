#include "../include/main.h"

#include <iostream>

int main(int, char**) {
    int check = 0;
    while (true) {
        std::cout << "Введите номер задачи, чтобы запустить её или 0, чтобы выйти\n";
        std::cin >> check;
        switch (check) {
            case 1:
                runFirstTask();
                break;
            case 2:
                runSecondTask();
                break;
            case 3:
                runThirdTask();
                break;
            case 4:
                runFourthTask();
                break;
            case 0:
                return 0;
            default:
                std::cout << "Такой задачи нет\n";
        }
    }
}
