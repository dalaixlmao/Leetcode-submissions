class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i < n && !isalpha(s[i]) && !isdigit(s[i]))
                i++;
            while (j >= 0 && !isalpha(s[j]) && !isdigit(s[j]))
                j--;
            // cout<<j<<" "<<i<<endl;
            if (i <= j && tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};