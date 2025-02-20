class Solution {
public:
    int jump(vector<int>& a) {
        if(a.size()==1)
        return 0;
        int n = a.size();
        int jump = 0;
        int l = 0, r = 0;
        while (r < n) {
            int mx = r + 1;
            for (int i = l; i <= r; i++) {
                mx = max(mx, a[i] + i);
            }
            l = r + 1;
            r = mx;
            jump++;
            if(r == n-1)
            return jump;
        }
        return jump;
    }
};