// Last updated: 5/8/2026, 6:38:36 PM
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        char ch;
        for (int i{0}; i < s.size(); i++) {
            ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(')
                    return false;
                if (ch == ']' && top != '[')
                    return false;
                if (ch == '}' && top != '{')
                    return false;
            }
        }
        return st.empty();
    }
};