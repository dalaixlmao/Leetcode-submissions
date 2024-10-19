class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m, mm;
        if(s.size()!=t.size())
        return false;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(m.count(s[i]))
            {
                if(m[s[i]]!=t[i])
                return false;
            }
            else{
                m[s[i]]=t[i];
            }

            if(mm.count(t[i]))
            {
                if(mm[t[i]]!=s[i])
                return false;
            }
            else{
                mm[t[i]]=s[i];
            }
        }
        return true;
    }
};