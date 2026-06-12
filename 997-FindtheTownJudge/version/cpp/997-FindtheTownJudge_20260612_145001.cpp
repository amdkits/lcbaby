// Last updated: 6/12/2026, 2:50:01 PM
/*
 * one map to store relationship
 * 1 -> 2
 * 4 -> 2
 * ...
 * 
 * one map to store how many relates to how many
 * 
 * 2 -> 5 people relates to 2
 * ...
 * 
 * then a loop from 1 to n
 * excavate if there is a relation where
 * one element is related by n-1 people
 * and that element's entry in mp has value 0
*/

1class Solution {
2public:
3    int findJudge(int n, vector<vector<int>>& trust) {
4        map<int, int> mp;
5        for (auto& t: trust)
6            mp[t[0]] = t[1];
7
8        map<int, int> trusted;
9        for (auto& t: trust)
10            trusted[t[1]]++;
11
12        for (int i = 1; i <= n; i++)
13            if (trusted[i] ==  n-1 && mp.count(i) == 0)
14                return i;
15        
16        return -1;
17    }
18};