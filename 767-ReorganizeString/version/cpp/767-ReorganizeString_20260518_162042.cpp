// Last updated: 5/18/2026, 4:20:42 PM
// heap is kinda brainy
1class Solution {
2public:
3    string reorganizeString(string S) {
4        string res = "";
5        unordered_map<char, int> mp;
6        priority_queue<pair<int, char>> pq;
7
8        for (auto s : S)
9            mp[s] += 1;
10
11        for (auto m : mp)
12            pq.push(make_pair(m.second, m.first));
13
14        while (pq.size() > 1) {
15            auto top1 = pq.top();
16            pq.pop();
17            auto top2 = pq.top();
18            pq.pop();
19
20            res += top1.second;
21            res += top2.second;
22
23            top1.first -= 1;
24            top2.first -= 1;
25
26            if (top1.first > 0)
27                pq.push(top1);
28
29            if (top2.first > 0)
30                pq.push(top2);
31        }
32
33        if (!pq.empty()) {
34            if (pq.top().first > 1)
35                return "";
36
37            else
38                res += pq.top().second;
39        }
40
41        return res;
42    }
43};