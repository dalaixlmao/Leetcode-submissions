

class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        int jump = 0;
        int l = 0, r = 0;
        while (r < n-1) {
            int far = 0;
            for (int i = l; i <= r; i++)
                far = max(far, a[i] + i);
            l = r+1;
            r=far;
            jump++;
        }
        return jump;
    }
};