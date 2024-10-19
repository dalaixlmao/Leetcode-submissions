class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        string t = "";
        while (i >= 0 && j >= 0) {
            int x = a[i] - '0';
            int y = b[j] - '0';
            int s = carry + x + y;
            carry = s / 2;
            t += '0' + s % 2;
            i--;
            j--;
        }
        while (i >= 0) {
            int x = a[i] - '0';
            int s = carry + x;
            carry = s / 2;
            t += '0' + s % 2;
            i--;
        }
        while (j >= 0) {
            int x = b[j] - '0';
            int s = carry + x;
            carry = s / 2;
            t += '0' + s % 2;
            j--;
        }
        if (carry)
            t += '0' + carry;
        reverse(t.begin(), t.end());
        return t;
    }
};