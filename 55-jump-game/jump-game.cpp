class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            if (farthest < i || (i<n-1 && a[i] == 0 && farthest == i))
                return false;
            farthest = max(farthest, i + a[i]);
        }
        return true;
    }
};