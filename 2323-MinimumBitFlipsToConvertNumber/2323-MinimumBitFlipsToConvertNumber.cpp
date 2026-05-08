// Last updated: 5/8/2026, 6:36:04 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int count;
        while (diff) {
            count += diff & 1;
            diff >>= 1;
        }
        return count;
    }
};