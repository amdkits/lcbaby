// Last updated: 5/8/2026, 6:36:54 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count{0}, maxlen{0};
        unordered_map<int, int> nyan;
        nyan[0] = -1;

             for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1, 1 as +1
            count += (nums[i] == 0 ? -1 : 1);

            if (nyan.find(count) != nyan.end()) {
                int length = i - nyan[count];
                maxlen = max(maxlen, length);
            } else {
                // Store first occurrence only
                nyan[count] = i;
            }
        }
        return maxlen;
    }
};