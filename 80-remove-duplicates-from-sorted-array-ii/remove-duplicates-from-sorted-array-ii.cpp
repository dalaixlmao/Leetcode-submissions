class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int flag = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            int x = i != 0 ? a[i - 1] : -10001;
            if (x != a[i]) {
                flag = 0;
                a[l] = a[i];
                l++;
            } else {
                if (!flag) {
                    a[l] = a[i];
                    flag = 1;
                    l++;
                } else
                    continue;
            }
        }
        return l;
    }
};