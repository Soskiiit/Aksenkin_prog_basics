#pragma once


namespace inverser {
    double** GenIdentityMatrix(int size);
    double** InverseMatrix(double** matrix, int n);
    void PrintMatrix(double** matrix, int n);
    void Solve();
}
