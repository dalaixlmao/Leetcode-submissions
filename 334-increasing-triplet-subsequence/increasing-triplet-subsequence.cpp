class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size();
        int mn = INT_MAX, mn2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] > mn) {
                mn2 = min(mn2, a[i]);
            }
            mn = min(mn, a[i]);
            if (a[i] > mn && a[i] > mn2)
                return true;
        }
        return false;
    }
};