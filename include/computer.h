#pragma once
#include "utils.h"


namespace computer {
    void StartApplication();

    double CalculateRectangle(
        double (*func)(double),
        double leftBound,
        double rightBound
    );

    double CalculateTrapezoid(
        double (*func)(double),
        double leftBound,
        double rightBound
    );

    double CalculateByPrecisionRectangle(
        double (*Function)(double),
        double (*ShapeFunc)(
            double (*Function)(double),
            double leftBound,
            double rightBound
        ),
        double intervalStart,
        double intervalEnd,
        double precision,
        utils::TableRow *result
    );
} // namespace computer
