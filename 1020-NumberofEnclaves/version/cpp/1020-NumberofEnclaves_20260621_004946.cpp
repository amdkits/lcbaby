// Last updated: 6/21/2026, 12:49:46 AM
1class Solution {
2public:
3    int ROWS, COLS;
4    vector<vector<bool>> visit;
5    vector<vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
6
7    int numEnclaves(vector<vector<int>>& grid) {
8        this->ROWS = grid.size();
9        this->COLS = grid[0].size();
10        this->visit = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
11
12        int land = 0, borderLand = 0;
13        for (int r = 0; r < ROWS; r++) {
14            for (int c = 0; c < COLS; c++) {
15                land += grid[r][c];
16                if (grid[r][c] == 1 && !visit[r][c] &&
17                    (r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1)) {
18                    borderLand += dfs(r, c, grid);
19                }
20            }
21        }
22        return land - borderLand;
23    }
24
25private:
26    int dfs(int r, int c, vector<vector<int>>& grid) {
27        if (r < 0 || c < 0 || r == ROWS || c == COLS || grid[r][c] == 0 ||
28            visit[r][c]) {
29            return 0;
30        }
31        visit[r][c] = true;
32        int res = 1;
33        for (auto& d : direct) {
34            res += dfs(r + d[0], c + d[1], grid);
35        }
36        return res;
37    }
38};