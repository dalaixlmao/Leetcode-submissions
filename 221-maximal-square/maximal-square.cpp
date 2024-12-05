class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = (i > 0) ? g[i - 1][j] - '0' : 0;
                int y = (j > 0) ? g[i][j - 1] - '0' : 0;
                int z = g[i][j] - '0';
                int zz = (i > 0 && j > 0) ? g[i - 1][j - 1] - '0' : 0;
                int mn = 0;
                if (x && y && z && zz) {
                    mn = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
                if (z)
                    dp[i][j] = mn + z;
                mx = max(mx, dp[i][j]);
            }
        }
        return mx * mx;
    }
};