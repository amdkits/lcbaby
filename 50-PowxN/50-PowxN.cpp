// Last updated: 5/8/2026, 6:38:14 PM
class Solution {
public:
    double myPow(double x, int n) {

        if (n < 0) {
            x = 1 / x;
        }

        long num = labs(n);

        double pow = 1;

        while (num) {
            if (num & 1)
                pow *= x;

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};