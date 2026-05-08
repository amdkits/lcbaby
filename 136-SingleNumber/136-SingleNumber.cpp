// Last updated: 5/8/2026, 6:37:44 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans{0};
        for (int i = 0; i < nums.size(); i++)
            ans ^= nums[i];
        return ans;
    }
};