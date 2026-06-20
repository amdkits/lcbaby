// Last updated: 6/21/2026, 12:52:48 AM
1class Solution {
2public:
3    int findCircleNum(vector<vector<int>>& isConnected) {
4        int n = isConnected.size();
5        vector<bool> visited(n, false);
6        int res = 0;
7
8        for (int i = 0; i < n; i++) {
9            if (!visited[i]) {
10                dfs(i, isConnected, visited, n);
11                res++;
12            }
13        }
14        return res;
15    }
16
17    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited,
18             int n) {
19        visited[node] = true;
20        for (int nei = 0; nei < n; nei++) {
21            if (isConnected[node][nei] == 1 && !visited[nei]) {
22                dfs(nei, isConnected, visited, n);
23            }
24        }
25    }
26};