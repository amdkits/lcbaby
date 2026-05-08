// Last updated: 5/8/2026, 6:37:21 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ein{0}, zwei{0};
        int sexy{-1}, back{-1};
        vector<int> mogs;

        for (auto x : nums) {
            if (x == sexy)
                ein++;
            else if (x == back)
                zwei++;
            else if (!ein) {
                sexy = x;
                ein++;
            } else if (!zwei) {
                back = x;
                zwei++;
            } else {
                ein--;
                zwei--;
            }
        }

        ein = 0;
        zwei = 0;

        for (auto x : nums) {
            if (x == sexy)
                ein++;
            else if (x == back)
                zwei++;
        }

        if (ein > nums.size() / 3)
            mogs.push_back(sexy);
        if (zwei > nums.size() / 3)
            mogs.push_back(back);
        return mogs;
    }
};