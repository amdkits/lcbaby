// Last updated: 6/13/2026, 1:29:57 PM
1class Solution {
2    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
3
4public:
5    int maxAreaOfIsland(vector<vector<int>>& grid) {
6        int m = grid.size(), n = grid[0].size(), count = 0;
7        for (int i = 0; i < m; i++)
8            for (int j = 0; j < n; j++)
9                if (grid[i][j] == 1)
10                    count = max(count, dfs(grid, i, j));
11        return count;
12    }
13
14    int dfs(vector<vector<int>>& grid, int r, int c) {
15        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
16            grid[r][c] == 0) {
17            return 0;
18        }
19
20        int res = 1;
21        grid[r][c] = 0;
22
23        for (int i = 0; i < 4; i++)
24            res += dfs(grid, r + directions[i][0], c + directions[i][1]);
25        return res;
26    }
27};