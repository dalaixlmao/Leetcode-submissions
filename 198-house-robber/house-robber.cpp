
class Solution {
public:
    int f(int i, vector<int>& a, vector<int>& dp) {

        if (i >= a.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int l = f(i + 2, a, dp) + a[i];
        int r = f(i + 1, a, dp);

        return dp[i] = max(l, r);
    }

    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n + 1, -1);
        return f(0, a, dp);
    }
};