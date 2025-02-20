class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int profit = 0;

        for (int i = 0; i < n; i++) {
            mn = min(mn, prices[i]);
            profit = max(profit, prices[i] - mn);
        }
        return profit;
    }
};