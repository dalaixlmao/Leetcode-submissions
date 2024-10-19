class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int total = a.size();
        if (b.size() == 0)
            return;

        int i1 = m - 1, i2 = total - 1;
        for (int i = i1; i >= 0; i--) {
            a[i2] = a[i];
            a[i] = 0;
            i2--;
        }
        int i = 0, j = total - m;
        int curr = 0;
        while (i < n && j < total) {
            if (a[j] < b[i]) {
                a[curr] = a[j];
                a[j] = 0;
                j++;
            } else {
                a[curr] = b[i];
                i++;
            }
            curr++;
        }
        while (i < n) {
            a[curr] = b[i];
            i++;
            curr++;
        }
    }
};