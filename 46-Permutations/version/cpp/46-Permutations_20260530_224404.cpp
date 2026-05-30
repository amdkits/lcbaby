// Last updated: 5/30/2026, 10:44:04 PM
1class Solution {
2public:
3    vector<vector<int>> permute(vector<int>& nums) {
4        vector<vector<int>> res;
5        backtrack(nums, 0, res);
6        return res;
7    }
8
9    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
10        if (start == nums.size()) {
11            res.push_back(nums);
12            return;
13        }
14
15        for (int i = start; i < nums.size(); i++) {
16            swap(nums[start], nums[i]);
17            backtrack(nums, start + 1, res);
18            swap(nums[start], nums[i]);
19        }
20    }
21
22    void swap(int& a, int& b) {
23        int temp = a;
24        a = b;
25        b = temp;
26    }
27};