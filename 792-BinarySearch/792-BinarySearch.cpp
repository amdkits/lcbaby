// Last updated: 5/8/2026, 6:36:45 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left{0}, right{n - 1}, mid{(left + right) / 2};
        do{
            mid = (left+right)/2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else
                return mid;
        } while (left <= right);
        return -1;
    }
};