// Last updated: 5/8/2026, 6:37:30 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, count{0};
        for (int i{0}; i < nums.size(); i++) {
            if (count == 0) res = nums[i];
            if (nums[i] == res)
                ++count;
            else
                --count;
        }
        return res;
    }
};