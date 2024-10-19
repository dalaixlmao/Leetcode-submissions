class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int l = 0, h = a.size()-1;
        int ans = a.size() - 1;
        while (l <= h) {
            int m = (l + h) >> 1;
            if(a[m]>=t)
            {
                h=m-1;
                ans = m;
            }
            else{
                l=m+1;
            }
        }
        if(a.back()<t)
        return a.size();
        else return ans;
    }
};