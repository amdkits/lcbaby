// Last updated: 5/8/2026, 6:36:15 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0, check = 0;
        for (i; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                check++;
        }
        if (nums[nums.size() - 1] > nums[0]) {
            check++;
        }
        return check <= 1;
    }
};