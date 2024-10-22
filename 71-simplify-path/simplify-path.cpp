class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        int n = path.size();
        string t = "";
        for (int i = 0; i < n; i++) {
            if (path[i] != '/')
                t += path[i];
            else {
                if (t != "") {
                    if (t == "..") {
                        if (!st.empty())
                            st.pop();
                    } else if (t == ".") {
                        t = "";
                        continue;
                    } else {
                        st.push(t);
                    }
                    t = "";
                }
            }
        }
        if (t != "") {
            if (t == "..") {
                if (!st.empty())
                    st.pop();
            } else if (t == ".") {
                t = "";
            } else {
                st.push(t);
            }
            t = "";
        }

        while (!st.empty()) {
            string dir = st.top();
            st.pop();
            reverse(dir.begin(), dir.end());
            ans += dir + "/";
        }
        reverse(ans.begin(), ans.end());
        if (ans == "")
            return "/";
        return ans;
    }
};