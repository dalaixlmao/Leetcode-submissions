class Solution {
public:
    vector<int> x = {1, 0};
    vector<int> y = {0, 1};

    int f(int i, int j, vector<vector<int>>& g, vector<vector<int>>& dp) {
        if (i == g.size() - 1 && j == g[0].size() - 1)
            return g[i][j];
        if (i == g.size() || j == g[0].size())
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = 0; k < 2; k++) {
            int nr = i + x[k];
            int nc = j + y[k];
            mn = min(mn, f(nr, nc, g, dp));
        }
        return dp[i][j] = mn + g[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, grid, dp);
    }
};