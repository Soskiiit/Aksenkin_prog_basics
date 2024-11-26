#include "computer.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

#include "utils.h"

namespace {
    const int kMinDecimalPlaces = 1;
    const int kMaxDecimalPlaces = 5;

    double LinearFunction(double x) {
        return x;
    }

    double ExponentialFunction(double x) {
        return std::pow(x, 4);
    }

    double TrigonometricFunction(double x) {
        return std::sin(22 * x);
    }

    double InverseTrigonometricFunction(double x) {
        return std::atan(x);
    }
}

namespace computer {
    double CalculateRectangle(
        double (*Function)(double),
        double leftBound,
        double rightBound
    ) {
        return Function((rightBound + leftBound) / 2.0) * (rightBound - leftBound);
    }

    double CalculateTrapezoid(
        double (*Function)(double),
        double leftBound,
        double rightBound
    ) {
        return (Function(leftBound) + Function(rightBound)) / 2.0 * (rightBound - leftBound);
    }

    void CalculateWithPrecision(
        double (*Function)(double),
        double (*CalculateSegmentArea)(
            double (*Function)(double),
            double leftBound,
            double rightBound
        ),
        double intervalStart,
        double intervalEnd,
        double precision,
        utils::TableRow *resultRow
    ) {
        int n = 1;
        double previousResult = 0;
        double result = CalculateSegmentArea(
            Function,
            intervalStart,
            intervalEnd
        );
        do {
            n *= 2;
            previousResult = result;
            result = 0;

            double step = (intervalEnd - intervalStart) / n;
            for (int i = 0; i < n; i++) {
                result += CalculateSegmentArea(
                    Function,
                    intervalStart + step * i,
                    intervalStart + step * (i + 1)
                );
            }
        } while (std::abs(previousResult - result) > precision);
        resultRow->i_sum = result;
        resultRow->n = n;
    }

    void StartApplication() {
        setlocale(LC_ALL, "Russian");

        int leftBoundary = utils::GenRandomNumber(0, 1);
        int rightBoundary = utils::GenRandomNumber(2, 3);
        std::cout << "a: " << leftBoundary << ", b: " << rightBoundary << std::endl;

        // Find accurate integral values
        double accurateLinearIntegralValue = (std::pow(rightBoundary, 2) - std::pow(leftBoundary, 2)) / 2.0;

        double accurateTrigonometricIntegralValue = (std::cos(22 * leftBoundary) - std::cos(22 * rightBoundary)) / 22.0;

        double accurateExponentialIntegralValue = std::abs(std::pow(leftBoundary, 5) - std::pow(rightBoundary, 5)) / 5.0;

        double accurateInverseTrigonometricIntegralValue = (
            rightBoundary * std::atan(rightBoundary)
            - leftBoundary * std::atan(leftBoundary)
            - (std::log(rightBoundary * rightBoundary + 1) - std::log(leftBoundary * leftBoundary + 1)) / 2.0
        );

        for (int decimalPlaces = kMinDecimalPlaces;
             decimalPlaces <= kMaxDecimalPlaces; decimalPlaces++) {
            double accuracy = std::pow(10, -decimalPlaces);
            utils::TableRow result[4];

            char methodNames[2][44] = {"Метод прямоугольников", "Метод трапеций"};
            double (*methodCalculateFunctions[2]) (double (*Function)(double), double, double) = {
                &CalculateRectangle,
                &CalculateTrapezoid
            };
            char functionNames[4][16] = {"y = x", "y = x ^ 4", "y = sin(22 * x)", "y = arctan(x)"};
            double (*functions[4])(double) = {
                &LinearFunction,
                &ExponentialFunction,
                &TrigonometricFunction,
                &InverseTrigonometricFunction
            };
            double accurateIntegralValues[4] = {
                accurateLinearIntegralValue,
                accurateExponentialIntegralValue,
                accurateTrigonometricIntegralValue,
                accurateInverseTrigonometricIntegralValue
            };
            // Calculations

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    utils::TableRow linearResult = {
                        .name = functionNames[j],
                        .i_sum = 0,
                        .i_toch = accurateIntegralValues[j],
                        .n = 0
                    };
                    CalculateWithPrecision(
                        functions[j],
                        methodCalculateFunctions[i],
                        leftBoundary,
                        rightBoundary,
                        accuracy,
                        &linearResult
                    );
                    result[j] = linearResult;
                }
                std::cout << "\n" << methodNames[i] << ". eps = " << std::fixed
                        << std::setprecision(decimalPlaces) << accuracy << std::endl;
                utils::PrintTable(result, 4);
            }
        }
    }
}
