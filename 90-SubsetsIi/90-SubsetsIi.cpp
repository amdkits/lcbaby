// Last updated: 5/8/2026, 6:37:50 PM
class Solution {
    void helper(int i, vector<int>& cur, vector<vector<int>>& result,
                vector<int>& nums) {
        if (i == nums.size())
            return;
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            cur.push_back(nums[j]);
            result.push_back(cur);
            helper(j + 1, cur, result, nums);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        result.push_back(cur);
        helper(0, cur, result, nums);
        return result;
    }
};