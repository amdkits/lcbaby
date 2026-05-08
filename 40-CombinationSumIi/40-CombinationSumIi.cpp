// Last updated: 5/8/2026, 6:38:19 PM
class Solution {
public:
    void dfs(int start, vector<int>& combo, int sum_now, vector<int>& candidates, int target, vector<vector<int>>& res) {
        if (sum_now == target) {
            res.push_back(combo);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (sum_now + candidates[i] > target) {
                break; 
            }

            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; 
            }

            combo.push_back(candidates[i]);
            dfs(i + 1, combo, sum_now + candidates[i], candidates, target, res); 
            combo.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combo;
        
        sort(candidates.begin(), candidates.end()); 
        
        dfs(0, combo, 0, candidates, target, res);
        return res;
    }
};