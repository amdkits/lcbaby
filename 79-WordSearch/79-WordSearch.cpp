// Last updated: 5/8/2026, 6:37:57 PM
class Solution {
public:
    bool explore(vector<vector<char>>& board, string word, int row, int col,
                 int index) {
        if (index == word.length())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if (board[row][col] != word[index])
            return false;

        char ch = board[row][col];
        board[row][col] = '#';

        if (explore(board, word, row + 1, col, index + 1) ||
            explore(board, word, row - 1, col, index + 1) ||
            explore(board, word, row, col + 1, index + 1) ||
            explore(board, word, row, col - 1, index + 1))
            return true;

        board[row][col] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (explore(board, word, i, j, 0)) return true;
        return false;
    }
};