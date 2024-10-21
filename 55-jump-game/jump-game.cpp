class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if(mx>=n-1)return true;
            if (mx == i && a[i] == 0) {
                return false;
            }
            if (mx < a[i] + i)
                mx = a[i] + i;
        }
        return true;
    }
};