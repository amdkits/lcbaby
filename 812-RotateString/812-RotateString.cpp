// Last updated: 5/8/2026, 6:36:44 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};