// Last updated: 5/14/2026, 1:24:59 AM
// had to do claude but now ik i need to read sm clrs
1class Solution {
2public:
3    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
4        priority_queue<pair<int, int>, vector<pair<int, int>>,
5                       greater<pair<int, int>>>
6            pq;
7
8        for (int i = 0; i < nums.size(); i++)
9            pq.push({nums[i], i});
10
11        while (k--) {
12            auto [val, idx] = pq.top();
13            pq.pop();
14            nums[idx] = val * multiplier;
15            pq.push({nums[idx], idx});
16        }
17
18        return nums;
19    }
20};