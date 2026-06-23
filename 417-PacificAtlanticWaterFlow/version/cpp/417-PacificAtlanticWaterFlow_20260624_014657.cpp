// Last updated: 6/24/2026, 1:46:57 AM
1class Solution {
2public:
3    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
4    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
5        int ROWS = heights.size(), COLS = heights[0].size();
6        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
7        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
8
9        for (int c = 0; c < COLS; c++) {
10            dfs(0, c, pac, heights); // top row -> pacific
11            dfs(ROWS - 1, c, atl, heights); // bottom row -> atlantic
12        }
13
14        for (int r = 0; r < ROWS; r++) {
15            dfs(r, 0, pac, heights); // left col -> pacific
16            dfs(r, COLS - 1, atl, heights); // right col -> atlantic
17        }
18
19        vector<vector<int>> res;
20        for (int r = 0; r < ROWS; r++)
21            for (int c = 0; c < COLS; c++)
22                if (pac[r][c] && atl[r][c]) // if both true i.e goes both corner
23                    res.push_back({r, c});
24
25        return res;
26    }
27
28private:
29    void dfs(int r, int c, vector<vector<bool>>& ocean,
30             vector<vector<int>>& heights) {
31        ocean[r][c] = true;
32        for (auto [dr, dc] : directions) {
33            int nr = r + dr, nc = c + dc;
34            if (nr >= 0 && nr < heights.size() && nc >= 0 &&
35                nc < heights[0].size() && !ocean[nr][nc] &&
36                heights[nr][nc] >= heights[r][c])
37                dfs(nr, nc, ocean, heights);
38        }
39    }
40};