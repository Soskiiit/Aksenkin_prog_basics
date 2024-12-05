#pragma once

namespace solution {
    struct SizedArray {
        int* data;
        int size;
    };

    SizedArray Factorize(int n);
    long long EulerFunc(long long p, long long q);
    void ExtendedEuclidean(long long a, long long b, long long& result1, long long& result2);
    long long ModPow(long long base, long long exp, long long mod);
    int Solve(int encryptedMessage, int e, int keyN);
}
