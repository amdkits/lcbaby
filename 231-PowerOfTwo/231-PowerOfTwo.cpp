// Last updated: 5/8/2026, 6:37:20 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};