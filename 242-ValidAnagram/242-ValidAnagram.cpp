// Last updated: 5/8/2026, 6:37:11 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char, int> nyan;

        for (char i : s)
            nyan[i]++;

        for (char c : t) {
            if (nyan.find(c) == nyan.end())
                return false;
            nyan[c]--;
            if (nyan[c] == 0)
                nyan.erase(c);
        }
        return nyan.empty();
    }
};