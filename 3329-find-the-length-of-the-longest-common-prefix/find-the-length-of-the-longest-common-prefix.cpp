class Solution {
public:

    bool can(int mid, vector<int> &a, vector<int> &b){
        int n=a.size(), m=b.size();
        map<string,int> ex;
        for(int i=0;i<n;i++)
        {
            string t = to_string(a[i]);
            if(t.size()>=mid)
            ex[t.substr(0, mid)]++;
        }

        for(int i=0;i<m;i++)
        {
            string t = to_string(b[i]);
            if(t.size()>=mid)
            {
                if(ex.count(t.substr(0, mid)))
                return true;
            }
        }
        return false;
    }

    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m = b.size();
        int h = 9;
        int l = 1;
        int ans=0;
        while(l<=h)
        {
            int mid = (l+h)>>1;
            int x = can(mid, a, b);
            if(x)
            {
                l=mid+1;
                ans=mid;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};