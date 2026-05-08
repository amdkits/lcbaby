// Last updated: 5/8/2026, 6:36:12 PM
class Solution {
public:
    string largestOddNumber(string num) {
        int n{(int)num.size()};
        for (int i{n - 1}; i >= 0; i--)
            if (num[i] % 2 != 0) {
                string s{num.substr(0, i + 1)};
                return s;
            }

        return "";
    }
};