// Last updated: 5/18/2026, 4:08:12 PM
// had to see solution, the code is still ain't in my brain
1class Solution {
2public:
3    vector<int> getOrder(vector<vector<int>>& tasks) {
4        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
5            available;
6        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pending;
7
8        int n = tasks.size();
9        for (int i = 0; i < n; ++i) {
10            pending.push({tasks[i][0], tasks[i][1], i});
11        }
12
13        vector<int> res;
14        long long time = 0;
15        while (!pending.empty() || !available.empty()) {
16            while (!pending.empty() && pending.top()[0] <= time) {
17                auto [enqueueTime, processTime, index] = pending.top();
18                pending.pop();
19                available.push({processTime, index});
20            }
21
22            if (available.empty()) {
23                time = pending.top()[0];
24                continue;
25            }
26
27            auto [processTime, index] = available.top();
28            available.pop();
29            time += processTime;
30            res.push_back(index);
31        }
32
33        return res;
34    }
35};