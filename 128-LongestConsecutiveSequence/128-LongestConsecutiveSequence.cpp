// Last updated: 5/8/2026, 6:37:45 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int length = 1, longest = 1;
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i - 1] + 1 == nums[i]) {
                length++;
                longest = max(length, longest);
            } else {
                length = 1;
            }
        }
        longest = max(length, longest);
        return longest;
    }
};