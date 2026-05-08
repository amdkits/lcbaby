// Last updated: 5/8/2026, 6:36:16 PM
class Solution {
public:
    int maxDepth(string s) {
        int count{0}, maxnum{0};
        for (char c : s) {
            if (c == '(') {
                count++;
                if (maxnum < count)
                    maxnum = count;
            } else if (c == ')')
                count--;
        }

        return maxnum;
    }
};