class Solution {
public:
    int f(int amt, int n, vector<int>& c, vector<int>& dp) {
        if (amt == 0)
            return 0;
        if (amt < 0)
            return 10001;
        if (dp[amt] != -1)
            return dp[amt];
        int mn = 10001;
        for (int j = 0; j < n; j++) {
            if (amt >= c[j])
                mn = min(mn, 1 + f(amt - c[j], n, c, dp));
        }
        return dp[amt] = mn;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(10001, -1);
        int x = f(amount, n, coins, dp);
        if (x == 10001)
            return -1;
        return x;
    }
};