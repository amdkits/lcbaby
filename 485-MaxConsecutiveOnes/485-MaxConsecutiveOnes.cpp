// Last updated: 5/8/2026, 6:37:00 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count{0}, res{0};
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i])
            count++;
            else
            count = 0;
            if (res < count)
                res = count;
        }
        return res;
    }
};