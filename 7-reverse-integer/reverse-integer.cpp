class Solution {
public:
    int reverse(int x) {
        int temp;
        string s = to_string(x);
        long long t = powl(2, 31);
        for (int i = 0; i < s.size() / 2; i++) {
            temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
        if (x < 0)
            s = "-" + s;
        long long p = stol(s);
        if(p<-t || p>t-1)
        return 0;
        return p;
    }
};