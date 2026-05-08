// Last updated: 5/8/2026, 6:37:48 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        for (int i = 0; i < numRows; i++) {
            nums.push_back(vector<int>(i + 1, 1));
            for (int j{1}; j < i; j++)
                nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
        }
        return nums;
    }
};