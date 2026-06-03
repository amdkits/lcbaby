// Last updated: 6/3/2026, 11:19:27 PM
1class Solution {
2public:
3    unordered_map<int,string> m1 = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
4
5    vector<string> letterCombinations(string digits) {
6        vector<string> ans;
7        int n = digits.size();
8        string temp = "";
9        backtrack(ans, temp, n, 0, digits);
10        return ans;
11    }
12
13    void backtrack(vector<string>& ans, string& temp, int n, int index, string digits) {
14        if(temp.size() == n) {
15            ans.push_back(temp);
16            return;
17        }
18
19        for (int i = 0; i < m1[digits[index] - '0'].size(); i++) {
20            temp += m1[digits[index] - '0'][i];
21            backtrack(ans, temp, n, index+1, digits);
22            temp.pop_back();
23        }
24    }
25};