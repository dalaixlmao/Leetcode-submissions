class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int longest = 0;
        for(int i = 0;i<n;i++)
        {
            if(i!=n-1 && longest == i && a[i]==0)
            return false;
            longest = max(longest, a[i]+i);
        }
        return true;
    }
};