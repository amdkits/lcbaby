// Last updated: 5/8/2026, 11:40:10 PM
// i have yet to learn heap tbh
1class KthLargest {
2public:
3    int K;
4    priority_queue<int, vector<int>, greater<int>> pq;
5
6    KthLargest(int k, vector<int>& nums) {
7        K = k;
8        for (int x : nums) {
9            add(x);
10        }
11    }
12    
13    int add(int val) {
14        pq.push(val);
15        if (pq.size() > K)
16            pq.pop();
17
18        return pq.top();
19    }
20};
21
22/**
23 * Your KthLargest object will be instantiated and called as such:
24 * KthLargest* obj = new KthLargest(k, nums);
25 * int param_1 = obj->add(val);
26 */