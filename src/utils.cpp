#include "utils.h"

#include <iostream>
#include <iomanip>
#include <cstring>
#include <random>

// This is unreadable, but i've just copypasted it)
namespace utils {
    int GenRandomNumber(int minVal, int maxVal) {
        // Initialize a random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(minVal, maxVal);

        // Generate random number in the range [min, max]
        int randomValue = distrib(gen);
        return randomValue;
    }

    void PrintTable(TableRow i_prn[], int k) {
        const char SIDE_SYBMOL = '|';
        const char HORIZONTAL_SYBMOL = '-';
        const char CONNECTOR_SYBMOL = '+';

        const int m = 4; // число столбцов таблицы
        int wn[m] = {24, 18, 18, 10}; // ширина столбцов таблицы
        char *title[m] = {(char *) "Function", (char *) "Integral", (char *) "IntSum", (char *) "N "};
        int size[m];
        for (int i = 0; i < m; i++) {
            size[i] = (int) strlen(title[i]);
        }
        // шапка таблицы
        std::cout << CONNECTOR_SYBMOL << std::setfill(HORIZONTAL_SYBMOL);
        for (int j = 0; j < m - 1; j++)
            std::cout << std::setw(wn[j]) << CONNECTOR_SYBMOL;
        std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::endl;

        std::cout << SIDE_SYBMOL;
        for (int j = 0; j < m; j++)
            std::cout << std::setw((wn[j] - size[j]) / 2) << std::setfill(' ') << ' ' << title[j]
                    << std::setw((wn[j] - size[j]) / 2) << SIDE_SYBMOL;
        std::cout << std::endl;

        // заполнение таблицы
        for (int i = 0; i < k; i++) {
            std::cout << CONNECTOR_SYBMOL << std::fixed;
            for (int j = 0; j < m - 1; j++)
                std::cout << std::setfill(HORIZONTAL_SYBMOL) << std::setw(wn[j]) << CONNECTOR_SYBMOL;
            std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::setfill(' ') << std::endl;

            std::cout << SIDE_SYBMOL << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
                    << std::setw((int) (wn[0] - strlen(i_prn[i].name)) / 2) << " " << SIDE_SYBMOL;
            std::cout << std::setw(wn[1] - 1) << std::setprecision(10) << i_prn[i].i_toch << SIDE_SYBMOL
                    << std::setw(wn[2] - 1) << i_prn[i].i_sum << std::setprecision(6) << SIDE_SYBMOL
                    << std::setw(wn[3] - 1) << i_prn[i].n << SIDE_SYBMOL << std::endl;
        }

        // низ таблицы
        std::cout << CONNECTOR_SYBMOL << std::setfill(HORIZONTAL_SYBMOL);
        for (int j = 0; j < m - 1; j++)
            std::cout << std::setw(wn[j]) << CONNECTOR_SYBMOL;
        std::cout << std::setw(wn[m - 1]) << CONNECTOR_SYBMOL << std::setfill(' ') << std::endl;
    }
}
