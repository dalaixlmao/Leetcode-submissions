class Solution {
public:
    bool canConstruct(string r, string m) {
        map<char, int> mp;
        int n=r.size();
        int n1 = m.size();
        for(int i=0;i<n1;i++)
        {
            mp[m[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            mp[r[i]]--;
            if(mp[r[i]]<0)
            return false;
        }
        return true;
        

    }
};