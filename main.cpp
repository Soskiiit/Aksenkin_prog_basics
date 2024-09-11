#include <iostream>

namespace {
const int minMinutes = 0;
const int minHours = 0;
const int morningStart = 5;
const int numericBase = 10;
const int startOfExceptionNums = 11;
const int halfADay = 12;
const int middayHours = 12;
const int middayMinutes = 0;
const int midnightHours = 0;
const int aOnEndOfWordEnd = 4;
const int midnightMinutes = 0;
const int endOfExceptionNums = 14;
const int eveningStart = 18;
const int maxHour = 23;
const int maxMinutes = 59;
}  // namespace

int main(int, char**) {
    int twentyFourFormatHours = 0;
    int hours = 0;
    int minutes = 0;
    bool invalidInput = false;

    std::cout << "Введите время (часы и минуты через пробел)\n";
    std::cin >> twentyFourFormatHours >> minutes;

    if (twentyFourFormatHours < minHours || twentyFourFormatHours > maxHour) {
        std::cout << "Столько часов не бывает!" << std::endl;
        invalidInput = true;
    }
    if (minutes < minMinutes || minutes >= maxMinutes) {
        std::cout << "Столько минут не бывает!" << std::endl;
        invalidInput = true;
    }
    if (invalidInput) {
        return 1;
    }

    if (twentyFourFormatHours == midnightHours && minutes == midnightMinutes) {
        std::cout << "полночь" << std::endl;
        return 0;
    }
    if (twentyFourFormatHours == middayHours && minutes == middayMinutes) {
        std::cout << "полдень" << std::endl;
        return 0;
    }

    hours = twentyFourFormatHours % halfADay;
    if (twentyFourFormatHours == halfADay) {
        std::cout << "12";
    } else {
        std::cout << hours;
    }

    if (hours == 1) {
        std::cout << " час";
    } else if (hours <= aOnEndOfWordEnd) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != minMinutes) {
        std::cout << " " << minutes;
        int lastDigit = minutes % numericBase;
        if (startOfExceptionNums <= minutes && minutes <= endOfExceptionNums) {
            std::cout << " минут";
        } else if (lastDigit == 0) {
            std::cout << " минут";
        } else if (lastDigit == 1) {
            std::cout << " минута";
        } else if (lastDigit == 2 || lastDigit == 3 || lastDigit == 4) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (morningStart <= twentyFourFormatHours && twentyFourFormatHours < halfADay) {
        std::cout << " утра";
    } else if (halfADay <= twentyFourFormatHours && twentyFourFormatHours < eveningStart) {
        std::cout << " дня";
    } else if (eveningStart <= twentyFourFormatHours && twentyFourFormatHours <= maxHour) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == minMinutes) {
        std::cout << " ровно";
    }
    std::cout << std::endl;

    return 0;
}
