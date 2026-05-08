// Last updated: 5/8/2026, 6:37:06 PM
class Solution {
public:
    int bulbSwitch(int n) {
        int i, count = 0;
        for (int i = 1; i*i <= n; i++){
            count++;
        }
        return count;
    }
};