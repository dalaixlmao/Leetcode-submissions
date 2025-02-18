class Solution {
public:
    string getSub(string& s, int l, int r) { return s.substr(l, r - l + 1); }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_map<string, bool> mp;
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        for (int i = 0; i < n; i++)
            mp[wordDict[i]] = true;
            n = s.size();
        for (int i = 0; i <= n; i++) {
            dp[i][n] = 0;
            if (i < n) {
                string t = getSub(s, i, n - 1);
                if (mp.count(t))
                    dp[i][n - 1] = 1;
                else
                    dp[i][n - 1] = 0;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n-2; j >= i; j--) {
                bool l, r;
                string t = getSub(s,  i, j);
                if (mp.count(t)) {
                    l = dp[j + 1][j + 1] & 1;
                    r = dp[i][j + 1];
                } else {
                    l = 0;
                    r = dp[i][j + 1];
                }
                dp[i][j] = l | r;
            }
        }

        return dp[0][0];
    }
};