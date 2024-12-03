class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            int ind = 0;
            if (j < spaces.size())
                ind = spaces[j];
            if (ind == i) {
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};