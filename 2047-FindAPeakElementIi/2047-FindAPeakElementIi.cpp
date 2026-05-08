// Last updated: 5/8/2026, 6:36:11 PM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m{(int)mat.size()}, n{(int)mat[0].size()}, col{0}, mid;
        int left{0}, right{n - 1};

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            bool leftBig = mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid];
            bool rightBig =
                mid < n - 1 && mat[maxRow][mid + 1] > mat[maxRow][mid];
            if (!leftBig && !rightBig)
                return {maxRow, mid};
            else if (rightBig)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return {-1, -1};
    }
};