class Solution {
public:
    int f(int i, int buy, vector<int>& p, vector<vector<int>>& dp) {

        if (i >= p.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int mx = 0;
        if (buy) {
            mx = max(f(i + 1, 0, p, dp) - p[i], f(i + 1, 1, p, dp));
        } else {
            mx = max(f(i + 1, 1, p, dp) + p[i], f(i + 1, 0, p, dp));
        }
        return dp[i][buy] = mx;
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return f(0, 1, p, dp);
    }
};