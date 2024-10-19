#define ll long long

class Solution {
public:
    int mySqrt(int x) {
        ll l = 0LL, h = (1 << 16);
        ll ans = 0LL;
        while (l <= h) {
            // cout << l << " " << h << endl;
            ll m = (h + l) >> 1;
            if (m * m > x) {
                h = m - 1;
            } else {
                l = m + 1;
                ans = m;
            }
        }
        return ans;
    }
};