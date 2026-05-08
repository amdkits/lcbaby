// Last updated: 5/8/2026, 6:36:29 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        std::stack<char> st;
        string result;
        for (int i=0; i<s.length(); i++){
            if (s[i] == '(') {
                if (!st.empty()) {
                    result += s[i];
                }
                st.push(s[i]);
            } 
            else {
                st.pop();
                if (st.empty() == 0) {
                    result += s[i];
                }
            }
        } 
        return result;    
    }
};