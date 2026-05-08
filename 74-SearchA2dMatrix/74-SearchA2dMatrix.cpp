// Last updated: 5/8/2026, 6:38:03 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0)
            return false;

        int m{(int)matrix.size()}, n{(int)matrix[0].size()};

        int low{0}, right{m * n - 1};

        while (low <= right) {
            int mid{low + (right - low) / 2};

            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                low = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};