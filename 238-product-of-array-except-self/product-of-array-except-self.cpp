class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int m=1,l=1;
        vector<int> p,s;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            p.push_back(m);
            m*=a[i];
            s.push_back(l);
            l*=a[n-i-1];
        }
        reverse(s.begin(),s.end());
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(p[i]*s[i]);
        }
        return ans;
        
    }
};