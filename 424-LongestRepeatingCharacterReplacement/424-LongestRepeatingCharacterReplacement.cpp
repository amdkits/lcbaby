// Last updated: 5/8/2026, 6:37:01 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int left{0}, maxFreq{0}, res{0};

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // window_size - maxFreq = replacements needed
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};