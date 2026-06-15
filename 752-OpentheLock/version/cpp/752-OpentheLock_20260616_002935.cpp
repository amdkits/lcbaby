// Last updated: 6/16/2026, 12:29:35 AM
1class Solution {
2public:
3    int openLock(vector<string>& deadends, string target) {
4        unordered_set<string> visit(deadends.begin(), deadends.end());
5        if (visit.count("0000"))
6            return -1;
7
8        queue<pair<string, int>> q;
9        q.push({"0000", 0});
10        visit.insert("0000");
11
12        while (!q.empty()) {
13            auto [lock, turns] = q.front();
14            q.pop();
15
16            if (lock == target)
17                return turns;
18            for (string child : children(lock)) {
19                if (!visit.count(child)) {
20                    visit.insert(child);
21                    q.push({child, turns + 1});
22                }
23            }
24        }
25        return -1;
26    }
27
28private:
29    vector<string> children(string lock) {
30        vector<string> res;
31        for (int i = 0; i < 4; ++i) {
32            string next = lock;
33            next[i] = (next[i] - '0' + 1) % 10 + '0';
34            res.push_back(next);
35
36            next = lock;
37            next[i] = (next[i] - '0' - 1 + 10) % 10 + '0';
38            res.push_back(next);
39        }
40        return res;
41    }
42};