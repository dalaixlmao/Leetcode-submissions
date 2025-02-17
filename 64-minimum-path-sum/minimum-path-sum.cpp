class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    vector<int> x = {1, 0};
    vector<int> y = {0, 1};

    int f(int i, int j, vector<vector<int>>& g, vector<vector<int>>& dp) {
        if (!isSafe(i, j, g.size(), g[0].size()))
            return 1e6;
        if (i == g.size() - 1 && j == g[0].size() - 1) {
            return g[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int l = f(i + 1, j, g, dp) + g[i][j];
        int r = f(i, j + 1, g, dp) + g[i][j];

        return dp[i][j] = min(l, r);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(0, 0, grid, dp);
    }
};