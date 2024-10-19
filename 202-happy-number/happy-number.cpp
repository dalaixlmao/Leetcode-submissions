class Solution {
public:
    int findSm(int n) {
        int x = n;
        int s = 0;
        while (x != 0) {
            int r = x % 10;
            s += r * r;
            x /= 10;
        }
        return s;
    }

    bool isHappy(int n) {
        queue<int> q;
        unordered_map<int, int> hash;
        int tt = n;
        while (true) {
            int num = tt;
            int sm = findSm(num);
            if (sm == 1)
                return true;
            if (hash.count(sm)) {
                return false;
            } else {
                hash[sm] = 1;
                tt=sm;
            }
        }
        return false;
    }
};