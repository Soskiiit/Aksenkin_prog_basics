#include "solution.h"

#include <iostream>

namespace solution {
    SizedArray Factorize(int n) {
        int *dividers = new int[30];
        int dividersCount = 0;
        int divider = 2;
        while (n > 1) {
            if (n % divider == 0) {
                dividers[dividersCount++] = divider;
                n = n / divider;
            } else {
                divider++;
            }
        }
        int *ans = new int[dividersCount];
        for (int i = 0; i < dividersCount; i++) {
            ans[i] = dividers[i];
        }
        delete[] dividers;

        return {ans, dividersCount};
    }

    long long EulerFunc(long long p, long long q) {
        return (p - 1) * (q - 1);
    }

    // Просто реализация отсюда
    // https://habrastorage.org/r/w1560/getpro/habr/upload_files/e3d/198/991/e3d1989911f827ee8c51e6a1be2203ee.png
    void ExtendedEuclidean(long long a, long long b, long long &result1, long long &result2) {
        long long q, r;
        long long x1 = 0;
        long long x2 = 1;
        long long y1 = 1;
        long long y2 = 0;

        while (b > 0) {
            q = a / b;
            r = a - q * b;
            long long x = x2 - q * x1;
            long long y = y2 - q * y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        result1 = x2;
        result2 = y2;
    }

    long long ModPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = result * base % mod;
            exp = exp / 2;
            base = base * base % mod;
        }
        return result;
    }

    int Solve(int encryptedMessage, int e, int keyN) {
        SizedArray dividers = Factorize(keyN);
        if (dividers.size != 2) {
            std::cout << "N должно состоять из 2 простых множителей" << std::endl;
            delete[] dividers.data;
            return 1;
        }
        long long firstDivider = dividers.data[0];
        long long secondDivider = dividers.data[1];

        long long eulerFuncResult = EulerFunc(firstDivider, secondDivider);

        long long x2, y2;
        long long secretKey;
        ExtendedEuclidean(eulerFuncResult, e, x2, y2);

        // From habr's article
        // secretKey = eulerFuncResult - std::abs(std::min(x2, y2));
        // Right method
        if (y2 < 0)
            secretKey = y2 + eulerFuncResult;
        else
            secretKey = y2;

        long long res = ModPow(encryptedMessage, secretKey, keyN);
        std::cout << "Результат расшифровки в задаче: " << res << std::endl;
        delete[] dividers.data;
        return 0;
    }
}
