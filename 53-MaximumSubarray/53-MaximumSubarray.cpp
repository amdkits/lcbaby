// Last updated: 5/8/2026, 6:38:11 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globular{nums[0]}, locular{nums[0]};
        for (int i{1}; i < nums.size(); i++) {
            locular = max(nums[i], locular + nums[i]);
            globular = max(locular, globular);
        }
        return globular;
    }
};