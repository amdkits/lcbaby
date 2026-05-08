// Last updated: 5/8/2026, 6:38:13 PM
class Solution {
public:
    void place(int row, int n, vector<string>& board,
               vector<vector<string>>& result, set<int>& cols, set<int>& diag1,
               set<int>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!cols.count(col) && !diag1.count(row - col) &&
                !diag2.count(row + col)) {
                cols.insert(col);
                diag1.insert(row - col);
                diag2.insert(row + col);
                board[row][col] = 'Q';

                place(row + 1, n, board, result, cols, diag1, diag2);

                cols.erase(col);
                diag1.erase(row - col);
                diag2.erase(row + col);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        set<int> cols, diag1, diag2;
        place(0, n, board, result, cols, diag1, diag2);
        return result;
    }
};