class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        map<char, char> mp = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (mp[st.top()] == s[i]) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        return st.size() == 0;
    }
};