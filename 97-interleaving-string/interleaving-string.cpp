class Solution {
public:
    int f(int i, int j, string s1, string s2, string s3,
          vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i < s1.size() && j < s2.size() && s1[i] == s3[i + j] &&
            s2[j] == s3[i + j]) {
            return dp[i][j] = f(i + 1, j, s1, s2, s3, dp) ||
                              f(i, j + 1, s1, s2, s3, dp);
        }
        if (i < s1.size() && s1[i] == s3[i + j]) {
            if (i == s1.size() - 1 && i+j == s3.size()-1)
                return dp[i][j] = true;
            return dp[i][j] = f(i + 1, j, s1, s2, s3, dp);
        }
        if (j < s2.size() && s2[j] == s3[i + j]) {
            if (j == s2.size() - 1 && i+j == s3.size()-1)
                return dp[i][j] = true;
            return dp[i][j] = f(i, j + 1, s1, s2, s3, dp);
        }
        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1 + s2 == s3)
            return true;
        if(s1.size()+s2.size()!=s3.size())
        return false;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int x = f(0, 0, s1, s2, s3, dp);
        return x;
    }
};