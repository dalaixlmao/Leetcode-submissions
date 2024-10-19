class Solution {
public:
    int romanToInt(string s) {
        map<char, int> val = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size();
        int sm = 0;
        for (int i = n - 1; i >= 0; i--) {
            int nxt = i != n - 1 ? val[s[i + 1]] : 0;
            int curr = val[s[i]];
            if (curr < nxt)
                sm -= curr;
            else
            sm += curr;
        }
        return sm;
    }
};