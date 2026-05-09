// Last updated: 5/10/2026, 12:14:15 AM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        unordered_map<char, int> mp;
5        int total{0};
6
7        for (char c : t) {
8            mp[c]++;
9            total++;
10        }
11
12        int index {0};
13        int ans = INT_MAX;
14        int start {0}, end {0};
15
16        while(end < s.length()) {
17            mp[s[end]]--;
18
19            if (mp[s[end]] >= 0)
20                total--;
21            
22            while(total == 0 && start <= end) {
23                if (end-start+1 < ans) {
24                    ans = end - start + 1;
25                    index = start;
26                }
27                if (mp[s[start]] >= 0)
28                    total++;
29                mp[s[start]]++;
30                start++;
31            }
32            end++;
33        }
34
35            string a = "";
36            if (ans == INT_MAX)
37                return "";
38            for (int i {index}; i < index+ans; i++)
39                a+=s[i];
40            return a;
41    }
42};