#include <iostream>
#include <string>

const int morningStart = 5;
const int ten = 10;
const int eleven = 11;
const int halfOfDay = 12;
const int fourteen = 14;
const int dayEveningJoint = 18;
const int maxHour = 23;
const int maxMinute = 59;

int main(int, char**) {
    int twFourFormatHours = 0;
    int hours = 0;
    int minutes = 0;
    std::cin >> twFourFormatHours >> minutes;
    if (twFourFormatHours < 0 || twFourFormatHours > maxHour || minutes < 0 || minutes >= maxMinute) {
        std::cout << "Введено недопустимое время" << std::endl;
        return 0;
    }
    // отлавливаем частные случаи
    if (twFourFormatHours == 0 && minutes == 0) {
        std::cout << "полночь" << std::endl;
        return 0;
    }
    if (twFourFormatHours == halfOfDay && minutes == 0) {
        std::cout << "полдень" << std::endl;
        return 0;
    }
    std::string partOfDay;
    std::string hoursLiteral;
    std::string minutesLiteral;
    if (morningStart <= twFourFormatHours && twFourFormatHours <= eleven) {
        partOfDay = "утра";
    } else if (halfOfDay <= twFourFormatHours && twFourFormatHours <= dayEveningJoint) {
        partOfDay = "дня";
    } else if (dayEveningJoint <= twFourFormatHours && twFourFormatHours <= maxHour) {
        partOfDay = "вечера";
    } else {
        partOfDay = "ночи";
    }
    hours = twFourFormatHours % halfOfDay;
    if (hours == 1) {
        hoursLiteral = "час";
    } else if (0 < hours && hours <= 4) {
        hoursLiteral = "часа";
    } else {
        hoursLiteral = "часов";
    }
    if (minutes == 0) {
        std::cout << hours << " " << hoursLiteral << " " << partOfDay << " ровно\n";
        return 0;
    }
    int lastDigit = minutes % ten;
    if ((eleven <= minutes && minutes <= fourteen) || lastDigit == 0) {
        minutesLiteral = "минут";
    } else if (lastDigit == 1) {
        minutesLiteral = "минута";
    } else if (lastDigit == 2 || lastDigit == 3 || lastDigit == 4) {
        minutesLiteral = "минуты";
    } else {
        minutesLiteral = "минут";
    }
    if (twFourFormatHours == halfOfDay) {
        std::cout << "12 " << hoursLiteral << " " << minutes << " " << minutesLiteral << " " << partOfDay << std::endl;
    } else {
        std::cout << hours << " " << hoursLiteral << " " << minutes << " " << minutesLiteral << " " << partOfDay << std::endl;
    }
    return 0;
}
