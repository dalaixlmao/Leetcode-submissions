class Solution {
public:
    bool f(int l, int r, string& s, unordered_map<string, bool>& g,
           vector<vector<int>>& dp) {

        if (r >= s.size())
            return false;

        if (dp[l][r] != -1)
            return dp[l][r];

        string t = s.substr(l, r - l + 1);

        if (r == s.size() - 1) {
            if (g.count(t))
                return true;
            return false;
        }
        bool p, q;
        if (g.count(t)) {
            p = f(r + 1, r + 1, s, g, dp) & 1;
            q = f(l, r + 1, s, g, dp);
        } else {
            p = 0;
            q = f(l, r + 1, s, g, dp);
        }
        return dp[l][r] = p | q;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_map<string, bool> mp;
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        for(int i = 0;i<n;i++) mp[wordDict[i]]=true;
        return f(0, 0, s, mp, dp);
    }
};