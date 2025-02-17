class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        if (n == 1)
            return 0;
        int l = 0, r = 0;
        int jumps = 0;
        while (r < n-1) {
            int mx = 0;
            for (int i = l; i <= r; i++) {
                mx = max(mx, a[i] + i);
            }
            l = r + 1;
            r = mx;
            // cout<<l<<" "<<r<<endl;
            if (l < n)
                jumps++;
        }
        return jumps;
    }
};