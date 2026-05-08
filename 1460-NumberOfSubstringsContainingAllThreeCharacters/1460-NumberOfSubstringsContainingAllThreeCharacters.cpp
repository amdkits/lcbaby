// Last updated: 5/8/2026, 6:36:24 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3] = {0};
        int l{0}, r{0}, count{0};

        while (r < s.size()) {
            if (s[r] == 'a' || s[r] == 'b' || s[r] == 'c')
                hash[s[r] - 'a']++;

            while (hash[0] && hash[1] && hash[2]) {
                count += s.size() - r;
                hash[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};