class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n=a.size();
        map<int,int> m;
        int r=n-1, l=0;
        while(l<=r)
        {
            if(a[l]+a[r]>t)
            {
                r--;
            }
            else{
                if(a[l]+a[r]==t)
                {
                    return {l+1, r+1};
                }
                else{
                    l++;
                }
            }
        }
        return {};
        
    }
};