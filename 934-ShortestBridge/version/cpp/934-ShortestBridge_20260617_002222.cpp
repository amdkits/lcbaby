// Last updated: 6/17/2026, 12:22:22 AM
1class Solution {
2public:
3    int N;
4    vector<vector<bool>> visited;
5    vector<vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
6
7    int shortestBridge(vector<vector<int>>& grid) {
8        N = grid.size();
9        visited = vector<vector<bool>>(N, vector<bool>(N, false));
10
11        bool found = false;
12        for (int r = 0; r < N; r++) {
13            if (found)
14                break;
15            for (int c = 0; c < N; c++) {
16                if (grid[r][c] == 1) {
17                    dfs(grid, r, c);
18                    found = true;
19                    break;
20                }
21            }
22        }
23
24        return bfs(grid);
25    }
26
27private:
28    void dfs(vector<vector<int>>& grid, int r, int c) {
29        if (r < 0 || c < 0 || r >= N || c >= N || grid[r][c] == 0 ||
30            visited[r][c])
31            return;
32
33        visited[r][c] = true;
34        for (auto& d : direct) {
35            dfs(grid, r + d[0], c + d[1]);
36        }
37    }
38
39    int bfs(vector<vector<int>>& grid) {
40        queue<pair<int, int>> q;
41        for (int r = 0; r < N; r++) {
42            for (int c = 0; c < N; c++) {
43                if (visited[r][c]) {
44                    q.push({r, c});
45                }
46            }
47        }
48
49        int res = 0;
50        while (!q.empty()) {
51            for (int i = q.size(); i > 0; i--) {
52                auto [r, c] = q.front();
53                q.pop();
54
55                for (auto& d : direct) {
56                    int curR = r + d[0], curC = c + d[1];
57
58                    if (curR < 0 || curC < 0 || curR >= N || curC >= N ||
59                        visited[curR][curC])
60                        continue;
61
62                    if (grid[curR][curC] == 1)
63                        return res;
64                    q.push({curR, curC});
65                    visited[curR][curC] = true;
66                }
67            }
68            res++;
69        }
70        return res;
71    }
72};