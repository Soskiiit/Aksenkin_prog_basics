#include "task2.h"

#include <iostream>

namespace {
const int kStartSequenceNegativeA = 3;
const int kEndSequenceNegativeA = 9;
const int kStepSequenceNegativeA = 3;

const int kStartSequenceNonNegativeA = 2;
const int kEndSequenceNonNegativeA = 8;
const int kStepSequenceNonNegativeA = 2;

const int kMinNonNegativeNumber = 0;

double ProductIfNegativeA() {
    double answer = 1;
    for (int i = kStartSequenceNegativeA; i <= kEndSequenceNegativeA; i += kStepSequenceNegativeA) {
        answer *= i;
    }
    answer -= 2;
    return answer;
}

double ProductIfNonNegativeA(double a) {
    double answer = 1;
    for (int i = kStartSequenceNonNegativeA; i <= kEndSequenceNonNegativeA; i += kStepSequenceNonNegativeA) {
        answer *= i * i - a;
    }
    return answer;
}
}  // namespace

void RunSecondTask() {
    double a = 0;
    std::cout << "Введите число а: ";
    std::cin >> a;
    std::cout << "Сумма ряда S равна: ";
    if (a < kMinNonNegativeNumber) {
        std::cout << ProductIfNegativeA() << std::endl;
    } else {
        std::cout << ProductIfNonNegativeA(a) << std::endl;
    }
}
