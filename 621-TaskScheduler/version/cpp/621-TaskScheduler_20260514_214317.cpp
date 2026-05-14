// Last updated: 5/14/2026, 9:43:17 PM
// it was hard i will revisit this one tbf
1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        unordered_map<char, int> mp;
5        priority_queue<pair<int, char>> pq;
6        int totalTasks = 0;
7
8        // Step 1: Count frequencies
9        for (char t : tasks) {
10            mp[t]++;
11            totalTasks++;
12        }
13
14        // Step 2: Build max heap
15        for (auto& i : mp) {
16            pq.push({i.second, i.first});
17        }
18
19        // Step 3: Cooldown queue
20        queue<pair<char, int>> waitQ;
21
22        int t = 0;
23
24        // Step 4: Simulation
25        while (totalTasks > 0) {
26
27            // Bring tasks back from cooldown
28            while (!waitQ.empty() && waitQ.front().second <= t) {
29                pq.push({mp[waitQ.front().first], waitQ.front().first});
30                waitQ.pop();
31            }
32
33            // Execute task if available
34            if (!pq.empty()) {
35                char task = pq.top().second;
36                pq.pop();
37
38                mp[task]--;
39                totalTasks--;
40
41                // Put back into cooldown if still remaining
42                if (mp[task] > 0) {
43                    waitQ.push({task, t + n + 1});
44                }
45            }
46
47            t++;
48        }
49        return t;
50    }
51};