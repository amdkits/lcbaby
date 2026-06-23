// Last updated: 6/24/2026, 12:54:10 AM
1class Solution {
2public:
3    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
4        unordered_map<string, vector<pair<string, double>>> adj; // Map a -> list of [b, a/b]
5
6        for (int i = 0; i < equations.size(); i++) {
7            string a = equations[i][0];
8            string b = equations[i][1];
9            adj[a].emplace_back(b, values[i]);
10            adj[b].emplace_back(a, 1.0 / values[i]);
11        }
12
13        vector<double> res;
14        for (const auto& query : queries) {
15            string src = query[0];
16            string target = query[1];
17            res.push_back(bfs(src, target, adj));
18        }
19
20        return res;
21    }
22
23private:
24    double bfs(const string& src, const string& target, unordered_map<string, vector<pair<string, double>>>& adj) {
25        if (!adj.count(src) || !adj.count(target)) {
26            return -1.0;
27        }
28
29        queue<pair<string, double>> q;
30        unordered_set<string> visited;
31        q.emplace(src, 1.0);
32        visited.insert(src);
33
34        while (!q.empty()) {
35            auto [node, weight] = q.front();
36            q.pop();
37
38            if (node == target) {
39                return weight;
40            }
41
42            for (const auto& [nei, neiWeight] : adj[node]) {
43                if (!visited.count(nei)) {
44                    visited.insert(nei);
45                    q.emplace(nei, weight * neiWeight);
46                }
47            }
48        }
49
50        return -1.0;
51    }
52};