#include <iostream>

namespace {
const int kMinMinutes = 0;
const int kMinHours = 0;
const int kMaxHour = 23;
const int kMaxMinutes = 59;

const int kHalfADay = 12;
const int kDecimalNumericBase = 10;

const int kMorningStart = 5;
const int kEveningStart = 18;

const int kMiddayHours = 12;
const int kMiddayMinutes = 0;
const int kMidnightHours = 0;
const int kMidnightMinutes = 0;

const int kStartGenitivePluralMinutes = 11;
const int kEndGenitivePluralMinutes = 14;
const int kStartOfGenitivePlural = 2;
const int kEndOfGenitivePlural = 4;
const int kNominativeSingularMinutes = 1;
const int kNominativeSingularHours = 1;
}  // namespace

int main(int, char**) {
    int twentyFourFormatHours = 0;
    int minutes = 0;

    std::cout << "Введите время (часы и минуты через пробел) (0 <= часы <= 23; 0 <= минуты <= 59)\n";
    std::cin >> twentyFourFormatHours >> minutes;

    if (twentyFourFormatHours < kMinHours || twentyFourFormatHours > kMaxHour) {
        std::cout << "Столько часов не бывает!" << std::endl;
        return 1;
    }
    if (minutes < kMinMinutes || minutes > kMaxMinutes) {
        std::cout << "Столько минут не бывает!" << std::endl;
        return 1;
    }

    if (twentyFourFormatHours == kMidnightHours && minutes == kMidnightMinutes) {
        std::cout << "Полночь" << std::endl;
        return 0;
    }
    if (twentyFourFormatHours == kMiddayHours && minutes == kMiddayMinutes) {
        std::cout << "Полдень" << std::endl;
        return 0;
    }

    int hours = twentyFourFormatHours % kHalfADay;
    if (twentyFourFormatHours == kHalfADay) {
        std::cout << kHalfADay;
    } else {
        std::cout << hours;
    }

    if (hours == kNominativeSingularHours) {
        std::cout << " час";
    } else if (hours <= kEndOfGenitivePlural && hours != kMinHours) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (kMinMinutes != minutes) {
        std::cout << " " << minutes;
        int lastDigit = minutes % kDecimalNumericBase;
        if (lastDigit == kNominativeSingularMinutes &&
            (minutes < kStartGenitivePluralMinutes || minutes > kEndGenitivePluralMinutes)) {
            std::cout << " минута";
        } else if (lastDigit >= kStartOfGenitivePlural && lastDigit <= kEndOfGenitivePlural &&
                   minutes < kStartGenitivePluralMinutes && minutes > kEndGenitivePluralMinutes) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (twentyFourFormatHours >= kMorningStart && twentyFourFormatHours < kHalfADay) {
        std::cout << " утра";
    } else if (twentyFourFormatHours >= kHalfADay && twentyFourFormatHours < kEveningStart) {
        std::cout << " дня";
    } else if (twentyFourFormatHours >= kEveningStart && twentyFourFormatHours <= kMaxHour) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == kMinMinutes) {
        std::cout << " ровно";
    }
    std::cout << std::endl;

    return 0;
}
