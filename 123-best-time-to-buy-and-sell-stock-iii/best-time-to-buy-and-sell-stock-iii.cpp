class Solution {
public:
    int f(int i, int buy, int tx, vector<int>& p,
          vector<vector<vector<int>>>& dp) {

        if (tx <= 0 || i >= p.size())
            return 0;
        int mx = 0;
        if (dp[i][buy][tx] != -1)
            return dp[i][buy][tx];
        if (buy) {
            mx = max(f(i + 1, 0, tx, p, dp) - p[i], f(i + 1, 1, tx, p, dp));
        } else {
            mx = max(f(i + 1, 1, tx - 1, p, dp) + p[i], f(i + 1, 0, tx, p, dp));
        }
        return dp[i][buy][tx] = mx;
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();
         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(4, -1)));
         return f(0, 1, 2, p, dp);
    }
};