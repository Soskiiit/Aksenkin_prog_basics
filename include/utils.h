#pragma once


namespace utils {
    struct TableRow {
        // данные для печати результатов интегрирования
        char *name; // название функции
        double i_sum; // значение интегральной суммы
        double i_toch; // точное значение интеграла
        int n; // число разбиений области при котором достигнута необх точность
    };

    void PrintTable(TableRow *table_rows, int i);
    int GenRandomNumber(int minVal, int maxVal);
}
