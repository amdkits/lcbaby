// Last updated: 5/8/2026, 6:37:53 PM
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!size(matrix)) return 0;
        int ans {0}, m {static_cast<int>(size(matrix))}, n {static_cast<int>(size(matrix[0]))};
        vector<vector<short>> dp(m+1, vector<short>(n+1));

        for (int i = m-1; ~i; i--)
            for (int j = n-1; ~j; j--)
                dp[i][j] = matrix[i][j] == '1' ? dp[i][j+1] + 1 : 0;

        for (int i {0}; i < m; i++)
            for (int j {0}; j < n; j++)
                for (int row {i}, colLen {n}; row < m && matrix[row][j] == '1'; row++) 
                    ans = max(ans, (row-i+1)*(colLen = min(colLen, dp[row][j]*1)));
        return ans;
    }
};