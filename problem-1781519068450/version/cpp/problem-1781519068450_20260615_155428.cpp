// Last updated: 6/15/2026, 3:54:28 PM
1class Solution {
2    int ROWS, COLS;
3    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
4
5public:
6    void solve(vector<vector<char>>& board) {
7        ROWS = board.size();
8        COLS = board[0].size();
9
10        capture(board);
11
12        for (int r = 0; r < ROWS; r++) {
13            for (int c = 0; c < COLS; c++) {
14                if (board[r][c] == 'O') {
15                    board[r][c] = 'X';
16                } else if (board[r][c] == 'T') {
17                    board[r][c] = 'O';
18                }
19            }
20        }
21    }
22
23private:
24    void capture(vector<vector<char>>& board) {
25        queue<pair<int, int>> q;
26        for (int r = 0; r < ROWS; r++) {
27            for (int c = 0; c < COLS; c++) {
28                if ((r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1) &&
29                    board[r][c] == 'O') {
30                    q.push({r, c});
31                }
32            }
33        }
34        while (!q.empty()) {
35            auto [r, c] = q.front();
36            q.pop();
37            if (board[r][c] == 'O') {
38                board[r][c] = 'T';
39                for (auto& direction : directions) {
40                    int nr = r + direction.first;
41                    int nc = c + direction.second;
42                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
43                        q.push({nr, nc});
44                    }
45                }
46            }
47        }
48    }
49};