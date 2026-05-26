// Last updated: 5/26/2026, 3:38:43 PM
1class Solution {
2public:
3    int subsetXORSum(vector<int>& nums) {
4        if (nums.size() == 0)
5            return 0;
6        int total {0};
7
8        for (int num : nums)
9            total |= num;
10
11        return total * ( 1 << (nums.size() - 1));
12    }
13};