class Solution {
public:
    vector<int> x = {1, 0};
    vector<int> y = {0, 1};
    int f(int i, int j, vector<vector<int>>& g, vector<vector<int>>& dp) {
        if (!(i >= 0 && j >= 0 && i < g.size() && j < g[0].size() &&
              g[i][j] == 0))
            return 0;
        if (i == g.size() - 1 && j == g[0].size() - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int s = 0;
        for (int k = 0; k < 2; k++) {
            int nr = i + x[k];
            int nc = j + y[k];
            s += f(nr, nc, g, dp);
        }
        return dp[i][j] = s;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, g, dp);
    }
};