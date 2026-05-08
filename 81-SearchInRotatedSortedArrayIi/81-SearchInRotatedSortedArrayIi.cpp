// Last updated: 5/8/2026, 6:37:56 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, right = (int)nums.size() - 1, mid;

        while (low <= right) {
            mid = (low + right) / 2;

            if (nums[mid] == target)
                return true;
            if ((nums[right] == nums[mid]) && (nums[low] == nums[mid])) {
                low++;
                right--;
            } else if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right])
                    low = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};