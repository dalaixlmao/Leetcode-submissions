class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int n = a.size();
        int r = 0, l = 0;
        int s = 0;
        int mn = INT_MAX;
        while (r < n) {
            s += a[r];
            while (l < r && s - a[l] >= t) {
                s -= a[l];
                l++;
            }
            if (s >= t) {
                mn = min(mn, r - l + 1);
            }
            r++;
        }
        if (mn == INT_MAX)
            return 0;
        return mn;
    }
};