// Last updated: 5/8/2026, 6:37:09 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans {0};
        for(int i = 0; i<=nums.size(); i++)
            ans = ans^i;
        for(int i = 0; i<nums.size(); i++)
            ans = ans^nums[i];
        return ans;
    }
};