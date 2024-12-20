#pragma once


namespace inverser {
    enum Action {
        MatrixInverse = 1,
        SolveSOLE = 2,
    };

    double** GenIdentityMatrix(int size);
    double** FindInverseMatrix(double** matrix, int n);
    void PrintMatrix(double** matrix, int n);
    void StartApplication();
}
