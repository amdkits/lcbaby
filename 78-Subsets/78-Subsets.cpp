// Last updated: 5/8/2026, 6:37:59 PM
class Solution {
public:
    void poopity(vector<int> &nums, int index, vector<vector<int>> &result, vector<int> &current) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        poopity(nums, index+1, result, current);

        current.pop_back();
        poopity(nums, index+1, result, current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        poopity(nums, 0, result, current);
        return result;
    }
};