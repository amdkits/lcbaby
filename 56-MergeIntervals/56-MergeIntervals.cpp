// Last updated: 5/8/2026, 6:38:08 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end());
        int eins{intervals[0][0]}, zwei{intervals[0][1]};
        vector<vector<int>> ans;
        for (auto v : intervals) {
            if (v[0] > zwei) {
                ans.push_back({eins, zwei});
                eins = v[0];
                zwei = v[1];
            } else if (v[1] > zwei)
                zwei = v[1];
        }
        ans.push_back({eins, zwei});
        return ans;
    }
};