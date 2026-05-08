// Last updated: 5/8/2026, 6:37:47 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximus{0}, minimus{prices[0]};
        for (int i = 0; i < prices.size(); i++) {
            minimus = min(minimus, prices[i]);
            maximus = max(maximus, prices[i]- minimus);
        }
        return maximus;
    }
};