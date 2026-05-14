// Last updated: 5/14/2026, 8:23:36 PM
// basis ahh question
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5
6        for (int i : nums) {
7            pq.push(i);
8            if (pq.size() > k)
9                pq.pop();
10        }
11
12        return pq.top();
13    }
14};