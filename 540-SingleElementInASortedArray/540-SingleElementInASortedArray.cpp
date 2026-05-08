// Last updated: 5/8/2026, 6:36:52 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, right = (int)nums.size() - 1, mid;

        while (low < right) {

            mid = low + (right - low) / 2;

            if (mid % 2 == 1)
                mid--;

            if ((mid % 2 == 0) && (nums[mid] == nums[mid + 1]))
                low = mid + 2;
            else
                right = mid;
        }
        return nums[low];
    }
};