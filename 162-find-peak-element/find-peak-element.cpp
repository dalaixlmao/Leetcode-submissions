class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n==1)
        return 0;
        if(a[0]>a[1])
        return 0;
        if(a[n-1]>a[n-2])
        return n-1;

        int l = 1, h = n - 2;
        while (l <= h) {
            int m = (l + h) >> 1;
            int x = a[m - 1];
            int y = a[m + 1];
            if (a[m] > x && a[m] > y) {
                return m;
            } else if (a[m] < x) {
                h = m - 1;
            } else {
                l=m+1;
            }
        }
        return 0;
    }
};