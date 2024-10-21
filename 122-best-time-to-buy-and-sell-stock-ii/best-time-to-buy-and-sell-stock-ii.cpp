class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    dp[i][j] = max(dp[i + 1][1] - p[i], dp[i + 1][0]);
                } else {
                    dp[i][j] = max(dp[i + 1][0] + p[i], dp[i + 1][1]);
                }
            }
        }
        return dp[0][0];
    }
};