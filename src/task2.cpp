#include <iostream>

#include "../include/main.h"

namespace {
const int kStartSequenceNegative = 3;
const int kEndSequenceNegative = 9;
const int kStepSequenceNegative = 3;

const int kStartSequenceNonNegative = 2;
const int kEndSequenceNonNegative = 8;
const int kStepSequenceNonNegative = 2;

const int kMinNonNegativeNumber = 0;
}  // namespace

double productIfNegative() {
    double answer = 1;
    for (int i = kStartSequenceNegative; i <= kEndSequenceNegative; i += kStepSequenceNegative) {
        answer *= i - 2;
    }
    return answer;
}

double productIfNonNegative(double a) {
    double answer = 1;
    for (int i = kStartSequenceNonNegative; i <= kEndSequenceNonNegative; i += kStepSequenceNonNegative) {
        answer *= i * i - a;
    }
    return answer;
}

void runSecondTask() {
    double a = 0;
    std::cout << "Введите число а: ";
    std::cin >> a;
    std::cout << "Сумма ряда S равна: ";
    if (a < kMinNonNegativeNumber) {
        std::cout << productIfNegative() << std::endl;
    } else {
        std::cout << productIfNonNegative(a) << std::endl;
    }
}
