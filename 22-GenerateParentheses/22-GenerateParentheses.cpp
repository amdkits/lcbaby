// Last updated: 5/8/2026, 6:38:33 PM
class Solution {
public:
    void backtrack(vector<string>& result, string cur, int oppun,
                   int cllosud, int n) {
        if (cur.length() == 2 * n) {
            result.push_back(cur);
            return;
        }

        if (oppun < n) {
            backtrack(result, cur + "(", oppun + 1, cllosud, n);
        }

        // Try adding ')'
        if (cllosud < oppun) {
            backtrack(result, cur + ")", oppun, cllosud + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};