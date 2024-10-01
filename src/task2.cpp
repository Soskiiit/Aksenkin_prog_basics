#include "task2.h"

#include <iostream>

namespace {
const int kStartSequenceNegative = 3;
const int kEndSequenceNegative = 9;
const int kStepSequenceNegative = 3;

const int kStartSequenceNonNegative = 2;
const int kEndSequenceNonNegative = 8;
const int kStepSequenceNonNegative = 2;

const int kMinNonNegativeNumber = 0;

double ProductIfNegative() {
    double answer = 1;
    for (int i = kStartSequenceNegative; i <= kEndSequenceNegative; i += kStepSequenceNegative) {
        answer *= i - 2;
    }
    return answer;
}

double ProductIfNonNegative(double a) {
    double answer = 1;
    for (int i = kStartSequenceNonNegative; i <= kEndSequenceNonNegative; i += kStepSequenceNonNegative) {
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
        std::cout << ProductIfNegative() << std::endl;
    } else {
        std::cout << ProductIfNonNegative(a) << std::endl;
    }
}
