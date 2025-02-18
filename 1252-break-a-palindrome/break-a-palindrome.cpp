class Solution {
public:
    string breakPalindrome(string a) {
        if (a.size()==1)
            return "";
        int n = a.size();
        int flag = 0;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] != 'a') {
                a[i] = 'a';
                flag = 1;
                return a;
            }
        }
        a[n - 1] = 'b';
        return a;
    }
};