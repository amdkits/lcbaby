// Last updated: 5/26/2026, 4:24:41 PM
1class Solution {
2public:
3    vector<vector<int>> combine(int n, int k) {
4        vector<vector<int>> res;
5        vector<int> comb;
6        poopity(1, res, comb, n, k);
7        return res;
8    }
9    void poopity(int start, vector<vector<int>>& res, vector<int>& comb, int n,
10                 int k) {
11        if (comb.size() == k) {
12            res.push_back(comb);
13            return;
14        }
15
16        for (int num{start}; num <= n; num++) {
17            comb.push_back(num);
18            poopity(num + 1, res, comb, n, k);
19            comb.pop_back();
20        }
21    }
22};