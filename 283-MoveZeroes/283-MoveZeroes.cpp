// Last updated: 5/8/2026, 6:37:07 PM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }
        if (j < 0)
            return;
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};