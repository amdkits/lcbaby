// Last updated: 5/8/2026, 6:36:09 PM
class Solution {
public:
    static const long long MOD = 1e9 + 7;
    long long modPow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1)
                r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

    int countGoodNumbers(long long n) {
        return modPow(5, (n + 1) / 2) * modPow(4, n / 2) % MOD;
    }
};