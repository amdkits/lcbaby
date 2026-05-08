// Last updated: 5/8/2026, 6:37:36 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, right = (int)nums.size() - 1, mid;

        while (low <= right) {
            mid = (right + low) / 2;

            if (nums[mid] < nums[right])
            right = mid;
            else
            low = mid + 1;
        }
        return nums[low - 1];
    }
};