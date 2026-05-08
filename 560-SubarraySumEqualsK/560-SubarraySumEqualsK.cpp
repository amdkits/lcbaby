// Last updated: 5/8/2026, 6:36:51 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> nyan;
        nyan[0] = 1;
        int count = 0, total = 0;
        for (int n : nums) {
            total += n;

            if (nyan.find(total-k) != nyan.end()) {
                count += nyan[total-k];
            }
            nyan[total]++;
        }
        return count;
    }
};