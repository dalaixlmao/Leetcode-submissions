class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        int sm = 1;

        int i = 1;
        int peak = 1;
        while (i < n) {

            if (r[i - 1] == r[i]) {
                i++;
                sm++;
                peak = 1;
                continue;
            }

            while (i < n && r[i - 1] < r[i]) {
                peak++;
                i++;
                sm += peak;
            }

            int down = 0;
            while (i < n && r[i - 1] > r[i]) {
                down++;
                i++;
                sm += down;
            }

            if (down + 1 > peak) {
                sm += down - peak + 1;
                peak = 1;
            }
            if(down>0)
            peak=1;
        }
        return sm;
    }
};