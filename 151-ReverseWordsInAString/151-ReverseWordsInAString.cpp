// Last updated: 5/8/2026, 6:37:38 PM
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i{0}, j{0}, start{0};
        int n{(int)s.length()};

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;

            while (i < n && s[i] != ' ')
                s[j++] = s[i++];
            reverse(s.begin() + start, s.begin() + j);
            s[j++] = ' ';
            start = j;
            i++;
        }
        s.resize(--j);
        return s;
    }
};