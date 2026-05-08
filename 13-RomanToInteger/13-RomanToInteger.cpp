// Last updated: 5/8/2026, 6:38:44 PM
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> nyan;
        int resi{0};
        
        // insert val to key in hashmap
        nyan['I'] = 1;
        nyan['V'] = 5;
        nyan['X'] = 10;
        nyan['L'] = 50;
        nyan['C'] = 100;
        nyan['D'] = 500;
        nyan['M'] = 1000;

        
        for (int i {0}; i < s.length()-1; i++) {
            if (nyan.at(s[i]) < nyan.at(s[i+1]))
                resi -= (nyan.at(s[i]));
            else
                resi += nyan.at(s[i]);
        }
        resi += nyan.at(s[s.length()-1]);
        return resi;
    }
};