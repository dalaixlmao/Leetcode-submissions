class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> prv(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    curr[j] = max(prv[1] - p[i], prv[0]);
                } else {
                    curr[j] = max(prv[0] + p[i], prv[1]);
                }
                prv = curr;
            }
        }
        return curr[0];
    }
};