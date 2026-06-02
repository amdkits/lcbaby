// Last updated: 6/2/2026, 8:27:21 PM
1class Solution {
2public:
3    void backtrack(string s, int i, int dots, string currIp,
4                   vector<string>& res) {
5        if (dots == 4 && i == s.length()) {
6            res.push_back(currIp.substr(0, currIp.length() - 1));
7            return;
8        }
9        if (dots > 4)
10            return;
11
12        for (int j = i; j < min(i + 3, (int)s.length()); j++) {
13            // the i==j check is used to determine if the current substring
14            // being considered as a part of the IP address is a single digit or
15            // not. If i is equal to j, it means that the current substring is a
16            // single digit. This check is used in conjunction with the check
17            // s[i] != '0' to ensure that the IP address being considered is a
18            // valid one, where each segment is between 0-255 and no leading
19            // zeroes are present.
20            if (stoi(s.substr(i, j - i + 1)) < 256 && (i == j || s[i] != '0')) {
21                backtrack(s, j + 1, dots + 1,
22                          currIp + s.substr(i, j - i + 1) + ".", res);
23            }
24        }
25    }
26    vector<string> restoreIpAddresses(string s) {
27        vector<string> res;
28        if (s.length() > 12)
29            return res;
30        backtrack(s, 0, 0, "", res);
31        return res;
32    }
33};