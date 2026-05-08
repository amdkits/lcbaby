// Last updated: 5/8/2026, 6:38:00 PM
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int total{0};

        for (char c : t) {
            mp[c]++;
            total++;
        }

        int index {0};
        int ans = INT_MAX;
        int start {0}, end {0};

        while(end < s.length()) {
            mp[s[end]]--;

            if (mp[s[end]] >= 0)
                total--;
            
            while(total == 0 && start <= end) {
                if (end-start+1 < ans) {
                    ans = end - start + 1;
                    index = start;
                }
                if (mp[s[start]] >= 0)
                    total++;
                mp[s[start]]++;
                start++;
            }
            end++;
        }

            string a = "";
            if (ans == INT_MAX)
                return "";
            for (int i {index}; i < index+ans; i++)
                a+=s[i];
            return a;
    }
};