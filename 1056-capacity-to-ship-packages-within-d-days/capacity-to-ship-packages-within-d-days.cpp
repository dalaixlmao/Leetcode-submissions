class Solution {
public:
    bool can(int m, vector<int>& w, int d) {
        int n = w.size();
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (s + w[i] <= m) {
                s += w[i];
            } else {
                s = w[i];
                d--;
            }
        }
        // cout<<m<<" "<<d<<endl;
        return d > 0;
    }

    int shipWithinDays(vector<int>& w, int d) {
        int n = w.size();
        int h = accumulate(w.begin(), w.end(), 0);

        int l = 0;
        for (int i = 0; i < n; i++)
            l = max(l, w[i]);
        int ans = h;
        while (l <= h) {
            int m = (l + h) >> 1;

            if (can(m, w, d)) {
                h = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};