class Solution {
public:
    string rev(string ss) {
        reverse(ss.begin(), ss.end());
        return ss;
    }

    string reverseWords(string s) {
        int n = s.size();
        string t = "";
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                t = t + s[i];
            } else {
                if (t != "") {
                    ans = t + " " + ans;
                    t="";
                }
            }
        }
        if (t != "") {
            ans = t + " " + ans;

        }
        ans.pop_back();
        string tt = rev(ans);
        return tt;
    }
};