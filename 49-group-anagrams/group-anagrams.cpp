class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        int n=a.size();
        map<multiset<char> , vector<string>> mp;
        for(int i=0;i<n;i++)
        {
            multiset<char> s;
            for(int j=0;j<a[i].size();j++)
            {
                s.insert(a[i][j]);
            }
            mp[s].push_back(a[i]);
        }
        vector<vector<string>> ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
        
    }
};