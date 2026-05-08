// Last updated: 5/8/2026, 6:36:57 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    for (int number : nums1) {
        auto it = find(nums2.begin(), nums2.end(), number);
        int nextGreater = -1;
        while (it != nums2.end()) {
            if (*it > number) {
                nextGreater = *it;
                break;
            }
            it++;
        }
        res.push_back(nextGreater);
    }
    return res;
}
};