class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> p;
        int mx = 0;
        while (r < n) {
            p[s[r]]++;
            while (l < r && p.size() < r - l + 1) {
                p[s[l]]--;
                if (p[s[l]] == 0)
                    p.erase(s[l]);
                l++;
            }
            mx=max(mx, r-l+1);
            r++;
        }
        return mx;

    }
};