class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 0;
        int count = 0;
        while (j < n) {
            int prv = j != 0 ? a[j - 1] : -101;
            if (a[j] != prv) {
                count++;
                a[i] = a[j];
                i++;
            }
            j++;
        }
        return count;
    }
};