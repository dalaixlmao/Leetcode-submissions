class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int l1 = 0, r1 = n - 1;
        int l2 = 0, r2 = n - 1;
        int l = 0, r = 0;
        int lt = 0, rt = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] == 'L') {
                l++;
                if (r != rt)
                    return false;
            }
            if (start[i] == 'R') {
                r++;
            }

            if (target[i] == 'L') {
                lt++;
                if (r != rt)
                    return false;
            }
            if (target[i] == 'R') {
                rt++;
            }
            if (l > lt)
                return false;
            if (r < rt)
                return false;
        }
        return (r == rt && l == lt);
    }
};