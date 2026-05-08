// Last updated: 5/8/2026, 6:37:12 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row{(int)matrix.size()}, col{(int)matrix[0].size()};

        for (int i{0}; i < row; i++) {
            int low{0}, right{col};
            while (low <= right) {
                int mid{low + (right - low) / 2};

                if (matrix[i][mid % col] == target)
                    return true;
                else if (matrix[i][mid % col] < target)
                    low = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};