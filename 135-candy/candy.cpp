class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> sf(n, 0), pf(n, 0);
        pf[0] = 1;
        sf[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (r[i] > r[i - 1]) pf[i] = pf[i - 1] + 1;
            else pf[i] = 1;
            if (r[n - i - 1] > r[n - i]) sf[n - i - 1] = sf[n - i] + 1;
            else sf[n - i - 1] = 1;
        }
        int s = 0;
        for (int i = 0; i < n; i++) s += max(pf[i], sf[i]);
        return s;
    }
};