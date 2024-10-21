

class Solution {
public:
    int f(int i, vector<int>& a, vector<int>& dp) {
        if (i >= a.size() - 1)
            return 0;
        if (a[i] == 0)
            return 1e6;
        int mn = 1e6;
        if (dp[i] != -1)
            return dp[i];
        for (int j = 1; j <= a[i]; j++) {
            mn = min(mn, 1 + f(i + j, a, dp));
        }
        return dp[i] = mn;
    }

    int jump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                dp[i] = 1e6;
        dp[n - 1] = 0;
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != 0) {
                int mn=1e6;
                for (int j = 1; j <= a[i]; j++) {
                    if(i==n-1)
                    mn=min(mn, 0);
                    else if(i+j>=n-1)
                    mn=min(mn, 1);
                    else
                    mn = min(mn, 1+dp[i+j]);
                }
                dp[i]=mn;
            }
        }
        return dp[0];
    }
};