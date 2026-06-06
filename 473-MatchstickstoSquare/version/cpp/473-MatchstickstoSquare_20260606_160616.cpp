// Last updated: 6/6/2026, 4:06:16 PM
1class Solution {
2public:
3    bool makesquare(vector<int>& matchsticks) {
4        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
5        if (sum % 4 != 0 || matchsticks.size() < 4)
6            return false;
7        sort(matchsticks.begin(), matchsticks.end());
8        vector<int> sides(4, 0);
9        return backtrack(matchsticks, sides, 0, sum / 4);
10    }
11    bool backtrack(vector<int>& v, vector<int>& sides, int i, int target) {
12        if (i == v.size())
13            return sides[0] == sides[1] && sides[1] == sides[2] &&
14                   sides[2] == sides[3];
15
16        for (int j = 0; j < 4; j++) {
17            if (sides[j] + v[i] > target)
18                continue;
19            sides[j] += v[i];
20            if (backtrack(v, sides, i + 1, target))
21                return true;
22            sides[j] -= v[i];
23            if (sides[j] == 0)
24                break;
25        }
26        return false;
27    }
28};