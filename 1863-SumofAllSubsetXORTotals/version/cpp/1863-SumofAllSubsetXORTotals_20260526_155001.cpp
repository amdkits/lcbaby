// Last updated: 5/26/2026, 3:50:01 PM
/*
 * backtracking.
 * 
 * The "Take" Branch: The code moves to the next index (i + 1) and includes the current number x in the subset. It updates the running total by XORing it with the current element (xorsum ^ x).
 * 
 * The "No Take" Branch: The code moves to the next index (i + 1) but excludes the current number. The xorsum remains unchanged.
 * 
 * Combining Results: The function returns take + notake, successfully adding the XOR totals from all subsets explored in both branches.
*/

1class Solution {
2public:
3    int n;
4    int subsetXORSum(vector<int>& nums) {
5        n = nums.size();
6        return f(0, 0, nums);
7    }
8    int f(int i, int xorsum, vector<int>& nums) {
9        if (i == n)
10            return xorsum;
11        int x = nums[i];
12        int take = f(i + 1, xorsum ^ x, nums);
13        int notake = f(i + 1, xorsum, nums);
14        return take+notake;
15    }
16};