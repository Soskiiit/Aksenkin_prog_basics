#include "matrixInverser.h"

#include <iomanip>
#include <iostream>
#include <unordered_map>


namespace inverser {
    const int kColumnWidth = 4;

    double** GenIdentityMatrix(int size) {
        double** identity = new double*[size];
        for (int i = 0; i < size; ++i) {
            identity[i] = new double[size] {0};
            identity[i][i] = 1;
        }
        return identity;
    }

    double** FindInverseMatrix(double** matrix, int n) {
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
        delete[] matrixCopy;
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

    void PrintRoots(double* roots, int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << "x" << i + 1 << " = " << roots[i] << std::endl;
        }
    }

    void DeleteMatrix(double** matrix, int n) {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    double** MultiplyMatrix(double** matrix1, double** matrix2, int n) {
        double** result = new double*[n];
        for (int i = 0; i < n; ++i) {
            result[i] = new double[n] {0};
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }

    bool InverseIsValid(double** matrix, double** inverseMatrix, int n) {
        double** result = MultiplyMatrix(matrix, inverseMatrix, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j && std::abs(result[i][j] - 1) > 1e-6) {
                    DeleteMatrix(result, n);
                    return false;
                }
                if (i != j && std::abs(result[i][j]) > 1e-6) {
                    DeleteMatrix(result, n);
                    return false;
                }
            }
        }
        DeleteMatrix(result, n);
        return true;
    }

    void RunInverseMatrixCase() {
        int n = 0;
        std::cout << "Введите размер матрицы, к которой нужно найти обратную: ";
        std::cin >> n;
        std::cout << "Введите матрицу " << n << "x" << n << std::endl;
        double** matrix = new double*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n] {0};
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        double** inverseMatrix = FindInverseMatrix(matrix, n);
        std::cout << "Исходная матрица:"<< std::endl;
        PrintMatrix(matrix, n);
        std::cout << "Обратная матрица:" << std::endl;
        PrintMatrix(inverseMatrix, n);
        if (InverseIsValid(matrix, inverseMatrix, n)) {
            std::cout << "\nОбратная матрица верна" << std::endl;
        } else {
            std::cout << "\nОбратная матрица неверна" << std::endl;
        }
        DeleteMatrix(matrix, n);
        DeleteMatrix(inverseMatrix, n);
    }

    void RunSOLECase() {
        int n = 0;
        std::cout << "Введите кол-во переменных: ";
        std::cin >> n;
        std::cout << "Введите расширенную матрицу с коэффициентами и ответами" << std::endl;
        double** matrix = new double*[n];
        double* answers = new double[n] {0};
        double* roots = new double[n] {0};
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n] {0};
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
            std::cin >> answers[i];
        }

        double** inverseMatrix = FindInverseMatrix(matrix, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                roots[i] += inverseMatrix[i][j] * answers[j];
            }
        }
        std::cout << "Система уравнений имеет следующие корни:" << std::endl;
        PrintRoots(roots, n);
        delete[] answers;
        delete[] roots;
        DeleteMatrix(matrix, n);
        DeleteMatrix(inverseMatrix, n);
    }

    void StartApplication() {
        int methodNumber = 0;
        std::cout << "Выберите решаемую задачу:" << std::endl;
        std::cout << "\t1)Нахождение обратной матрицы" << std::endl;
        std::cout << "\t2)Решение СЛАУ" << std::endl;

        std::cin >> methodNumber;
        switch (static_cast<Action>(methodNumber)) {
            case MatrixInverse:
                RunInverseMatrixCase();
                break;
            case SolveSOLE:
                RunSOLECase();
        }
    }
}
