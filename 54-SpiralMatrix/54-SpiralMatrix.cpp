// Last updated: 5/8/2026, 6:38:09 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = n - 1;
        int t = 0, b = m - 1;
        vector<int> mat;

        while (t <= b && l <= r) {
            for (int i = l; i <= r; i++) {
                mat.push_back(matrix[t][i]);
            }
            t+=1;
            for (int i = t; i <= b; i++) {
                mat.push_back(matrix[i][r]);
            }
            r-=1;
            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    mat.push_back(matrix[b][i]);
                }
                b-=1;
            }
            if (l <= r) {
                for (int i = b; i >= t; i--) {
                    mat.push_back(matrix[i][l]);
                }
                l+=1;
            }
        }
        return mat;
    }
};