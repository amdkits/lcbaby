// Last updated: 5/8/2026, 6:36:41 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (low <= right) {

            int mid = low + (right - low) / 2;
            long long kh = 0;

            for (int i = 0; i < piles.size(); i++)
                kh += (piles[i] + mid - 1) / mid;

            if (kh <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};