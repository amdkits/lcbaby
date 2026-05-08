// Last updated: 5/8/2026, 6:38:39 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i{0}; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j{i + 1}; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[k] + (long long)nums[l];

                    if (sum < target)
                        k++;
                    else if (sum > target)
                        l--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        int lastK = nums[k];
                        int lastL = nums[l];
                        while (k < l && nums[k] == lastK)
                            k++;
                        while (k < l && nums[l] == lastL)
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};