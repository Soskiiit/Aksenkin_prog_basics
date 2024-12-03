#include "mprinter.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>


namespace mprinter {
    const int kDefaultMaxLineLength = 80;

    long Factorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    int GenRandomNumber(int minVal, int maxVal) {
        // Initialize a random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(minVal, maxVal);

        // Generate random number in the range [min, max]
        int randomValue = distrib(gen);
        return randomValue;
    }

    double GenerateMatrixElementUpper(int row, int col) {
        return 1.0 / std::pow(Factorial(col), row);
    }

    double GenerateMatrixElementLower(int row, int col) {
        if (row % 2 == 0) return 1.0 / std::pow(Factorial(col), row);
        return -1.0 / std::pow(Factorial(col), row);
    }


    double **CreateMatrix(int rows, int cols) {
        auto **matrix = new double *[rows];
        // Iterates over matrix and creates every row
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[cols];
        }
        return matrix;
    }

    void DeleteMatrix(double **matrix) {
        delete[] matrix;
    }

    void FillMatrix(double **matrix, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i < j) matrix[i][j] = GenerateMatrixElementUpper(i, j);
                else if (i > j) matrix[i][j] = GenerateMatrixElementLower(i, j);
                else matrix[i][j] = 1;
            }
        }
    }

    void PrintMatrix(double **matrix, int rows, int cols, int precision, int maxLineLength=kDefaultMaxLineLength) {
        int oneElementWidth = precision + 9; // margin(7) + "0." + precision
        int elenemtsInOneRow = maxLineLength / oneElementWidth;
        int tableWidth = std::min(oneElementWidth * std::min(elenemtsInOneRow, cols) + 9, maxLineLength + 9);
        int pagesCount = cols / elenemtsInOneRow;
        if (cols % elenemtsInOneRow != 0) pagesCount++;

        // Print "=======..." (start of table) and configures output
        std::cout << std::setprecision(precision) << std::fixed << std::setfill('=');
        std::cout << std::setw(tableWidth) << "=" << std::endl << std::setfill(' ');

        // Printing table
        for (int i = 0; i < pagesCount; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < elenemtsInOneRow; k++) {
                    if (i * elenemtsInOneRow + k < cols)
                        std::cout << std::setw(oneElementWidth) << matrix[j][i * elenemtsInOneRow + k];
                }
                std::cout << std::endl;
            }
            // If it was last row and wasn't last page separates pages by print "-------..."
            if (i != pagesCount - 1) {
                std::cout << std::setfill('-') << std::setw(tableWidth) << '-' << std::endl;
                std::cout << std::setfill(' ');
            }
        }
        // Prints "=======..." (end of table)
        std::cout << std::setfill('=') << std::setw(tableWidth) << "=" << std::endl << std::setfill(' ');
    }

    void RunApplication() {
        // Part 1
        std::cout << std::endl << "Part 1" << std::endl;

        int rows = GenRandomNumber(8, 15);
        int cols = GenRandomNumber(8, 15);
        int precision = GenRandomNumber(3, 8);
        std::cout << "Rows: " << rows << "\tCols: " << cols << "\tPrecision: " << precision << std::endl << std::endl;

        double **matrix = CreateMatrix(rows, cols);
        FillMatrix(matrix, rows, cols);
        PrintMatrix(matrix, rows, cols, precision);
        DeleteMatrix(matrix);

        // Part 2
        std::cout << std::endl << "Part 2" << std::endl;

        double staticMatrix[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                staticMatrix[i][j] = i * 10 + j;
            }
        }
        double* serviceArray[10];
        for (int i = 0; i < 10; i++) {
            serviceArray[i] = staticMatrix[i];
        }
        PrintMatrix(serviceArray, 10, 10, 0);

        // Part 3
        std::cout << std::endl << "Part 3" << std::endl;

        // Prints first line address 2 times and address of 3rd line
        std::cout << staticMatrix << "  " << staticMatrix[0] << "  " << staticMatrix[2] << std::endl;
        // First matrix element via 3 methods
        std::cout << staticMatrix[0][0] << "  " << **staticMatrix << "  " << *staticMatrix[0] << std::endl;
        // First elem of 2nd line via 2 methods
        std::cout << *(*(staticMatrix + 1)) << "  " << *staticMatrix[1] << std::endl;
        // 2nd elem 1st line
        std::cout << *(staticMatrix[0] + 1) << "  " << *(*staticMatrix + 1) << std::endl;
        // 3rd line 21st element
        std::cout << staticMatrix[0][20] << "  " << *(staticMatrix[0] + 20) << "  " << *staticMatrix[2] << std::endl;
    }
}
