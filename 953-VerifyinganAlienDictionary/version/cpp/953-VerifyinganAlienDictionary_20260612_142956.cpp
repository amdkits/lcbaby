// Last updated: 6/12/2026, 2:29:56 PM
/*
 * checks word before it and compares letter by letter
 * if smth is out of order, return false
 * if all the words match for the less length with the more length string,
 * checks if previous word is greater than the next word and return false if it is
*/

1class Solution {
2public:
3    bool isAlienSorted(vector<string>& words, string order) {
4        unordered_map<char, int> mp;
5
6        for (int i = 0; i < order.size(); i++)
7            mp[order[i]] = i;
8
9        for (int i = 1; i < words.size(); i++) {
10            string w1 = words[i-1];
11            string w2 = words[i];
12
13            int size = min(w1.size(), w2.size());
14
15            for (int j = 0; j < size; j++) {
16                if (mp[w1[j]] < mp[w2[j]])
17                    break;
18                else if (mp[w1[j]] == mp[w2[j]]) {
19                    if ( j == size - 1 && w1.size() > w2.size())
20                        return false;
21                }
22                else
23                    return false;
24            }
25        }
26        return true;
27    }
28};