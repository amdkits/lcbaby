// Last updated: 5/14/2026, 12:48:25 AM
// heap first
1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq(stones.begin(), stones.end());
5
6        while (pq.size() > 1) {
7            int a = pq.top();
8            pq.pop();
9            int b = pq.top();
10            pq.pop();
11
12            if (a != b)
13                pq.push(abs(a-b));
14        }
15
16        return pq.empty() ? 0 : pq.top();
17    }
18};