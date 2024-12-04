class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        while (j < m && i < n) {
            int c = s1[i] - 'a';
            int d = s2[j] - 'a';
            int e = (c + 1) % 26;
            if (e == d || c==d)
                j++;
            i++;
        }
        return j == m;
    }
};