// Last updated: 6/17/2026, 8:28:06 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int N = grid.size();
5        if (grid[0][0] == 1 || grid[N - 1][N - 1] == 1)
6            return -1;
7
8        vector<pair<int, int>> directions = {{0, 1},  {1, 0}, {0, -1},
9                                             {-1, 0}, {1, 1}, {-1, -1},
10                                             {1, -1}, {-1, 1}};
11        vector<vector<bool>> visited(N, vector<bool>(N, false));
12
13        queue<tuple<int, int, int>> q;
14
15        q.push({0, 0, 1});
16        visited[0][0] = true;
17
18        while (!q.empty()) {
19            auto [r, c, length] = q.front();
20            q.pop();
21
22            if (r == N - 1 && c == N - 1)
23                return length;
24
25            for (auto [dr, dc] : directions) {
26                int nr = r + dr, nc = c + dc;
27                if (nr >= 0 && nc >= 0 && nr < N && nc < N &&
28                    grid[nr][nc] == 0 && !visited[nr][nc]) {
29                    q.push({nr, nc, length + 1});
30                    visited[nr][nc] = true;
31                }
32            }
33        }
34        return -1;
35    }
36};