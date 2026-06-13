// Last updated: 6/13/2026, 11:42:35 AM
1class Solution {
2public:
3    int countServers(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        vector<int> rowcount(m, 0), colcount(n, 0);
6
7        // pass 1: tally
8        for (int i = 0; i < m; i++)
9            for (int j = 0; j < n; j++)
10                if (grid[i][j] == 1) {
11                    rowcount[i]++;
12                    colcount[j]++;
13                }
14
15        // pass 2: count servers that can communicate
16        int ans = 0;
17        for (int i = 0; i < m; i++)
18            for (int j = 0; j < n; j++)
19                if (grid[i][j] == 1 && (rowcount[i] > 1 || colcount[j] > 1))
20                    ans++;
21        return ans;
22    }
23};