class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int mx = 0;
        while (l <= r) {
            mx = max(mx, min(h[l], h[r]) * (r - l));
            if (h[r] < h[l]) {
                r--;
            } else if (h[r] > h[l]) {
                l++;
            } else {
                r--;
                l++;
            }
        }
        return mx;
    }
};