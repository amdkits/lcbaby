// Last updated: 5/8/2026, 6:36:06 PM
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        long long totalSum = 0;

        for (int i{0}; i < n; i++) {
            int currMin = nums[i];
            int currMax = nums[i];
            for (int j{i}; j < n; j++) {
                currMin = min(currMin, nums[j]);
                currMax = max(currMax, nums[j]);
                totalSum += (currMax - currMin);
            }
        }
        return totalSum;
    }
};