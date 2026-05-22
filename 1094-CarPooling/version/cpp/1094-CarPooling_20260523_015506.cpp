// Last updated: 5/23/2026, 1:55:06 AM
1class Solution {
2public:
3    bool carPooling(vector<vector<int>>& trips, int capacity) {
4        map<int, int> mp;
5
6        for (int i {0}; i < trips.size(); i++) {
7            int passengers {trips[i][0]};
8            int enter {trips[i][1]};
9            int leave {trips[i][2]};
10
11
12            mp[enter] += passengers;
13            mp[leave] -= passengers;
14        }
15        int currp {0};
16
17        for (auto it:mp) {
18            currp += it.second;
19            if (currp > capacity)
20                return false;
21        }
22        return true;
23    }
24};