// Last updated: 5/8/2026, 6:36:26 PM
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low{1}, right{*max_element(nums.begin(), nums.end())};
        int mid, fin;

        while (low <= right) {
            mid = low + (right - low) / 2;
            long long ans = 0;

            for (int i : nums)
                ans += (i + mid - 1) / mid;

            if (ans <= threshold) {
                fin = mid;
                right = mid - 1;
            } else
                low = mid + 1;
        }
        return fin;
    }
};