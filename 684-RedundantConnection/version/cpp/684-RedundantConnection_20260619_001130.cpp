// Last updated: 6/19/2026, 12:11:30 AM
1class Solution {
2public:
3    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
4        int n = edges.size();
5        vector<vector<int>> adj(n + 1);
6
7        for (const auto& edge : edges) {
8            int u = edge[0], v = edge[1];
9            adj[u].push_back(v);
10            adj[v].push_back(u);
11            vector<bool> visit(n + 1, false);
12
13            if (dfs(u, -1, adj, visit))
14                return {u, v};
15        }
16        return {};
17    }
18
19private:
20    bool dfs(int node, int parent, vector<vector<int>>& adj,
21             vector<bool>& visit) {
22        if (visit[node])
23            return true;
24        visit[node] = true;
25        for (int nei : adj[node]) {
26            if (nei == parent)
27                continue;
28            if (dfs(nei, node, adj, visit))
29                return true;
30        }
31        return false;
32    }
33};