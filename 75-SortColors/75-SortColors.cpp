// Last updated: 5/8/2026, 6:38:02 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low {}, mid {}, high {static_cast<int>(nums.size())-1};
        while (mid<=high)
        if (nums[mid] ==0) swap(nums[mid++], nums[low++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
};