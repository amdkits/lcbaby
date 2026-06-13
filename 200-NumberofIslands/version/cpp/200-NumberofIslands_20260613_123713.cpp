// Last updated: 6/13/2026, 12:37:13 PM
1class Solution {
2    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
3public:
4    int numIslands(vector<vector<char>>& grid) {
5        int ROWS = grid.size(), COLS = grid[0].size();
6        int islands = 0;
7
8        for (int r = 0; r < ROWS; r++) {
9            for (int c = 0; c < COLS; c++) {
10                if (grid[r][c] == '1') { // any 1 encountered
11                    dfs(grid, r, c); // calls dfs on it
12                    islands++; // islands + 1
13                }
14            }
15        }
16
17        return islands;
18    }
19
20    void dfs(vector<vector<char>>& grid, int r, int c) {
21        if (r < 0 || c < 0 || r >= grid.size() ||
22            c >= grid[0].size() || grid[r][c] == '0') {
23            return;
24        } // returns nothing if out of bound or water
25
26        grid[r][c] = '0'; // changes island to 0
27        for (int i = 0; i < 4; i++) { 
28            dfs(grid, r + directions[i][0], c + directions[i][1]);
29        } // calls dfs on up, down, left and right.
30    }
31};