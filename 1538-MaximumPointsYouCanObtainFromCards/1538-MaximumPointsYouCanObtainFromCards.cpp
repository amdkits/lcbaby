// Last updated: 5/8/2026, 6:36:23 PM
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res{0};
        int dupk {k};

        for (int nums : cardPoints) {
            res += nums;
            dupk--;
            if (!dupk)
                break;
        }
        
        int curr {res};
        for (int i {k-1}; i >= 0; i--) {
            curr -= cardPoints[i];
            curr += cardPoints[cardPoints.size() - k + i];

            res = max(res, curr);
        }
        return res;
    }
};