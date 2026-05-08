// Last updated: 5/8/2026, 6:37:31 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, right = (int)nums.size() - 1, mid;
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return 0;

        while (low < right) {
            mid = low + (right - low) / 2;

            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                right = mid;
        }
        return low;
    }
};