class Solution {
public:
    string convert(string s, int r) {
        int n = s.size();
        vector<string> h(r, "");
        if (r == 1)
            return s;
        int f = 2 * r - 2;
        for (int i = 0; i < n; i++) {
            int l = i / f;
            int r = l + 1;
            int ind = min(abs(f * l - i), abs(r * f - i));
            h[ind] += s[i];
        }
        string ans = "";
        for (int i = 0; i < r; i++) {
            ans += h[i];
        }
        return ans;
    }
};