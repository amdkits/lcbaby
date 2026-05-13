// Last updated: 5/14/2026, 12:56:53 AM
// holy shit i was just learning and damn
1class Solution {
2public:
3    long long pickGifts(vector<int>& gifts, int k) {
4        make_heap(gifts.begin(), gifts.end());
5        while (k) {
6            k--;
7            pop_heap(gifts.begin(), gifts.end());
8            // int x = gifts.back();
9            gifts.back() = sqrt(gifts.back());
10            push_heap(gifts.begin(), gifts.end());
11        }
12        return accumulate(gifts.begin(), gifts.end(), 0LL);
13    }
14};