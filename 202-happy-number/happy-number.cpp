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
        q.push(n);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            int sm = findSm(num);
            if (sm == 1)
                return true;
            if (hash.count(sm)) {
                return false;
            } else {
                hash[sm] = 1;
                q.push(sm);
            }
        }
        return false;
    }
};