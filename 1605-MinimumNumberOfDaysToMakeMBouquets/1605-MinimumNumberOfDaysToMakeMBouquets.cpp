// Last updated: 5/8/2026, 6:36:21 PM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low{1}, right{*max_element(bloomDay.begin(), bloomDay.end())};
        int mid, days{-1}, countofbouquet, total;

        while (low <= right) {
            mid = low + (right - low) / 2;
            total = 0;
            countofbouquet = 0;

            for (int i{0}; i < bloomDay.size(); i++)
                if (bloomDay[i] <= mid) {
                    countofbouquet++;
                    if (countofbouquet == k) {
                        total++;
                        countofbouquet = 0;
                    }
                } else
                    countofbouquet = 0;
            if (total >= m) {
                days = mid;
                right = mid - 1;
            } else
                low = mid + 1;
        }
        return days;
    }
};