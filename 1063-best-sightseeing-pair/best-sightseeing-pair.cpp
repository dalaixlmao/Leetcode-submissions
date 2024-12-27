class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            a.push_back(values[i] + i);
            b.push_back(values[i] - i);
        }
        int mx = INT_MIN;
        int m = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                m = max(m, values[n - i - 1] + n - i - 1 + mx);
            mx = max(mx, values[n - i - 1] - (n - i - 1));
        }
        return m;
    }
};