// Last updated: 6/12/2026, 1:43:12 PM
// BFS Q1
1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        int cnt = 0;
7
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (grid[i][j] == 1) {
11                    if ((j > 0 && grid[i][j - 1] == 0) || j == 0)
12                        cnt++;
13                    if ((i > 0 && grid[i - 1][j] == 0) || i == 0)
14                        cnt++;
15                    if ((j < m - 1 && grid[i][j + 1] == 0) || j == m - 1)
16                        cnt++;
17                    if ((i < n - 1 && grid[i + 1][j] == 0) || i == n - 1)
18                        cnt++;
19                }
20            }
21        }
22        return cnt;
23    }
24};