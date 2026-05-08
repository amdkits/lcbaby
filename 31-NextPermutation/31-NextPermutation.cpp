// Last updated: 5/8/2026, 6:38:27 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index{-1}, n = nums.size();
        for (int i = nums.size() - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = {n - 1}; i > index; i--)
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }

        reverse(begin(nums) + (index + 1), end(nums));
    }
};