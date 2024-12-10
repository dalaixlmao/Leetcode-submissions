class Solution {
public:
    int chkSp(string s) {
        char c = s[0];
        for (auto i : s)
            if (i != c)
                return false;
        return true;
    }
    int chk(string& s, int m) {
        map<string, int> mp;
        int n = s.size();
        for (int i = 0; i < n - m + 1; i++) {
            string t = s.substr(i, m);
            if (chkSp(t)) {
                mp[t]++;
                if (mp[t] >= 3)
                    return true;
            }
        }
        return false;
    }

    int maximumLength(string s) {
        int n = s.size();
        int mx = -1;
        int c = 0;
        int l = 1, h = n;
        while (l <= h) {
            int m = (l + h) >> 1;
            int x = chk(s, m);
            if (x) {
                l = m + 1;
                mx = m;
            } else {
                h = m - 1;
            }
        }
        return mx;
    }
};