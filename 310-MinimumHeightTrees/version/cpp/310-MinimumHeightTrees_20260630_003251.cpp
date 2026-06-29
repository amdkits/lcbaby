// Last updated: 6/30/2026, 12:32:51 AM
// neetcode, yet to fully grasp
1class Solution {
2private:
3    vector<vector<int>> adj;
4    vector<vector<int>> dp;
5
6    void dfs(int node, int parent) {
7        for (int nei : adj[node]) {
8            if (nei == parent)
9                continue;
10            dfs(nei, node);
11            int curHgt = 1 + dp[nei][0];
12            if (curHgt > dp[node][0]) {
13                dp[node][1] = dp[node][0];
14                dp[node][0] = curHgt;
15            } else if (curHgt > dp[node][1]) {
16                dp[node][1] = curHgt;
17            }
18        }
19    }
20
21    void dfs1(int node, int parent, int topHgt) {
22        if (topHgt > dp[node][0]) {
23            dp[node][1] = dp[node][0];
24            dp[node][0] = topHgt;
25        } else if (topHgt > dp[node][1]) {
26            dp[node][1] = topHgt;
27        }
28
29        for (int nei : adj[node]) {
30            if (nei == parent)
31                continue;
32            int toChild = 1 + ((dp[node][0] == 1 + dp[nei][0]) ? dp[node][1]
33                                                               : dp[node][0]);
34            dfs1(nei, node, toChild);
35        }
36    }
37
38public:
39    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
40        adj.resize(n);
41        dp.assign(n, vector<int>(2, 0)); // top two heights for each node
42        for (const auto& edge : edges) {
43            adj[edge[0]].push_back(edge[1]);
44            adj[edge[1]].push_back(edge[0]);
45        }
46
47        dfs(0, -1);
48        dfs1(0, -1, 0);
49
50        int minHgt = n;
51        vector<int> res;
52        for (int i = 0; i < n; i++) {
53            minHgt = min(minHgt, dp[i][0]);
54        }
55        for (int i = 0; i < n; i++) {
56            if (minHgt == dp[i][0]) {
57                res.push_back(i);
58            }
59        }
60        return res;
61    }
62};