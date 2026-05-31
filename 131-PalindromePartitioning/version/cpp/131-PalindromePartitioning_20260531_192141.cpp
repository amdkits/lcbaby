// Last updated: 5/31/2026, 7:21:41 PM
1class Solution {
2public:
3    vector<vector<string>> partition(string s) {
4        vector<vector<string>> result;
5        vector<string> path;
6        backtrack(s, 0, path, result);
7        return result;
8    }
9
10private:
11    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
12        if (start == s.length()) {
13            result.push_back(path);
14            return;
15        }
16        for (int end = start + 1; end <= s.length(); ++end) {
17            if (isPalindrome(s, start, end - 1)) {
18                path.push_back(s.substr(start, end - start));
19                backtrack(s, end, path, result);
20                path.pop_back();
21            }
22        }
23    }
24
25    bool isPalindrome(const string& s, int left, int right) {
26        while (left < right) {
27            if (s[left++] != s[right--]) {
28                return false;
29            }
30        }
31        return true;
32    }
33};