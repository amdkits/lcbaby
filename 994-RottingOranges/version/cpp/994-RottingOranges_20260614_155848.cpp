// Last updated: 6/14/2026, 3:58:48 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        queue<pair<int, int>> q;
5        int fresh = 0, time = 0;
6
7        for (int r = 0; r < grid.size(); r++)
8            for (int c = 0; c < grid[0].size(); c++) {
9                if (grid[r][c] == 1)
10                    fresh++;
11                if (grid[r][c] == 2)
12                    q.push({r, c});
13            }
14        
15        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
16
17        while(fresh && !q.empty()){
18            int length = q.size();
19            for (int i = 0; i < length; i++) {
20                auto curr = q.front();
21                q.pop();
22                int r = curr.first;
23                int c = curr.second;
24
25                for(const auto& dir : directions) {
26                    int row = r + dir.first;
27                    int col = c + dir.second;
28
29                    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1) {
30                        grid[row][col] = 2;
31                        q.push({row, col});
32                        fresh--;
33                    }
34                }
35            }
36            time++;
37        }
38        return fresh == 0 ? time : -1;
39    }
40};