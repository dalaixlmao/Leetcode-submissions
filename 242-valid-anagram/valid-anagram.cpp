class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        int n = s.size();
        if (s.size() != t.size())
            return false;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            mp[t[i]]--;
            if (mp[t[i]] == 0)
                mp.erase(t[i]);
        }
        return mp.size() == 0;
    }
};