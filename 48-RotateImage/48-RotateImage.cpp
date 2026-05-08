// Last updated: 5/8/2026, 6:38:15 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};