// Last updated: 5/8/2026, 6:36:03 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> falafel(nums.size(), 0);
        int pp{0}, neg{1};
        for (int i{0}; i < nums.size(); i++) {
            int& idx = (nums[i] > 0) ? pp : neg;
            falafel[idx] = nums[i];
            idx += 2;
        }
        return falafel;
    }
};