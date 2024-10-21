

class Solution {
public:
    int f(int i, vector<int>& a, vector<int> &dp) {
        if (i >= a.size()-1)
            return 0;
        if (a[i] == 0)
            return 1e6;
        int mn = 1e6;
        if(dp[i]!=-1)
        return dp[i];
        for (int j = 1; j <= a[i]; j++) {
            mn = min(mn, 1 + f(i + j, a, dp));
        }
        return dp[i]=mn;
    }

    int jump(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n+1, -1);
        int x = f(0, a, dp);
        return x;
    }
};