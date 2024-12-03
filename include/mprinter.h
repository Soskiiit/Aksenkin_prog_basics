namespace mprinter {
    const int kDefaultMaxLineLength = 80;
    const int kDefaultPrecision = 3;

    double** CreateMatrix(int row, int col);
    void PrintMatrix(double **matrix, int rows, int cols,
        int precision = kDefaultPrecision,
        int maxLineLength = kDefaultMaxLineLength
    );
    void FillMatrix(int **matrix, int rows, int cols);
    void RunApplication();
}
