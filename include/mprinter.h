#include <iomanip>

namespace mprinter {
    const int kDefaultMaxLineLength = 80;
    const int kDefaultPrecision = 3;

    enum class OutputMode {
        Fixed = 1,
        Scientific = 2
    };

    double** CreateMatrix(int row, int col);
    void PrintMatrix(double **matrix, int rows, int cols, OutputMode outputMode,
        int precision = kDefaultPrecision,
        int maxLineLength = kDefaultMaxLineLength
    );
    void FillMatrix(int **matrix, int rows, int cols);
    void RunApplication();
}
