// Last updated: 5/8/2026, 6:36:47 PM
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count {0};

        for (int i {left}; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if (is_prime(setBits))
                count++;
        }
        return count;
    }

private:
    bool is_prime(int n) {
        if (n<=1)
            return false;
        for (int i {2}; i*i <= n; i++)
            if (n%i == 0)
                return false;
        return true;
    }
};