// Last updated: 5/8/2026, 6:36:18 PM
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (const string& step : logs) {
            if (step == "../") {
                // Only decrease depth if we aren't already at the root
                if (depth > 0) {
                    depth--;
                }
            } 
            else if (step != "./") {
                // If it's "x/", we go one level deeper
                depth++;
            }
            // "./" is ignored automatically as it doesn't match either condition
        }
        
        return depth;
    }
};