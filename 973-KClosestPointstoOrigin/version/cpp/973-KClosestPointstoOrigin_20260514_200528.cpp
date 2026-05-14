// Last updated: 5/14/2026, 8:05:28 PM
// worked a bit hard and learned a bit more
1class Solution {
2public:
3    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
4        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
5
6        for (auto& p: points) {
7            int dist = p[0]*p[0] + p[1]*p[1];
8            pq.push({dist, p});
9        }
10        
11        vector<vector<int>> result;
12        while (k--) {
13            result.push_back(pq.top().second);
14            pq.pop();
15        }
16        return result;
17    }
18};