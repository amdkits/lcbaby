// Last updated: 6/16/2026, 12:35:22 AM
1class Solution {
2public:
3    int openLock(vector<string>& deadends, string target) {
4        if (target == "0000") return 0;
5
6        unordered_set<string> visit(deadends.begin(), deadends.end());
7        if (visit.count("0000")) return -1;
8
9        queue<string> q;
10        q.push("0000");
11        visit.insert("0000");
12        int steps = 0;
13
14        while (!q.empty()) {
15            steps++;
16            for (int i = q.size(); i > 0; i--) {
17                string lock = q.front(); q.pop();
18                for (int j = 0; j < 4; j++) {
19                    for (int move : {1, -1}) {
20                        string nextLock = lock;
21                        nextLock[j] = (nextLock[j] - '0' + move + 10) % 10 + '0';
22                        if (visit.count(nextLock)) continue;
23                        if (nextLock == target) return steps;
24                        q.push(nextLock);
25                        visit.insert(nextLock);
26                    }
27                }
28            }
29        }
30        return -1;
31    }
32};