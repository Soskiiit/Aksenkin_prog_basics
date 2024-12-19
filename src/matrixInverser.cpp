#include "matrixInverser.h"

#include <iomanip>
#include <iostream>


namespace inverser {
    const int kColumnWidth = 8;

    double** GenIdentityMatrix(int size) {
        double** identity = new double*[size];
        for (int i = 0; i < size; ++i) {
            identity[i] = new double[size] {0};
            identity[i][i] = 1;
        }
        return identity;
    }

    double** InverseMatrix(double** matrix, int n) {
        double** matrixCopy = new double*[n];
        for (int i = 0; i < n; ++i) {
            matrixCopy[i] = new double[n] {0};
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrixCopy[i][j] = matrix[i][j];
            }
        }

        double** inverseMatrix = GenIdentityMatrix(n);

        for (int i = 0; i < n; ++i) {
            double diagElement = matrixCopy[i][i];
            if (diagElement == 0) {
                std::cerr << "Матрица вырожденная, к ней не существует обратной" << std::endl;
                exit(EXIT_FAILURE);
            }

            for (int j = 0; j < n; ++j) {
                matrixCopy[i][j] /= diagElement;
                inverseMatrix[i][j] /= diagElement;
            }

            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    double factor = matrixCopy[k][i];
                    for (int j = 0; j < n; ++j) {
                        matrixCopy[k][j] -= factor * matrixCopy[i][j];
                        inverseMatrix[k][j] -= factor * inverseMatrix[i][j];
                    }
                }
            }
        }

        return inverseMatrix;
    }

    void PrintMatrix(double** matrix, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << "\t\t" << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }

    void DeleteMatrix(double** matrix, int n) {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void Solve() {
        int n = 0;
        std::cout << "Введите размер матрицы, к которой нужно найти обратную: ";
        std::cin >> n;
        std::cout << "Введите матрицу NxN" << std::endl;
        double** matrix = new double*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n] {0};
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        double** inverseMatrix = InverseMatrix(matrix, n);
        std::cout << "Исходная матрица:"<< std::endl;
        PrintMatrix(matrix, n);
        std::cout << "Обратная матрица:" << std::endl;
        PrintMatrix(inverseMatrix, n);
        DeleteMatrix(matrix, n);
        DeleteMatrix(inverseMatrix, n);
    }
}
