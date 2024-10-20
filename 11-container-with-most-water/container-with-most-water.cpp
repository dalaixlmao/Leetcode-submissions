class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n-1;
        int mx = INT_MIN;
        while (l<r) {
            mx = max(mx, min(a[r], a[l])*(r-l));
            if(a[l]<a[r])
            l++;
            else
            r--;
        }
        return mx;
    }
};