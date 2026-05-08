// Last updated: 5/8/2026, 6:38:53 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) != h.end()) {
                return {h[target - nums[i]], i};
            }
            h[nums[i]] = i;
        }
        return {};
    }
};