class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int l = strs[0].size();
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<min(strs[i].size(), strs[0].size());j++)
            {
                if(strs[i][j]==strs[0][j])
                c++;
                else
                break;
            }
            l = min(l, c);
        }
        return strs[0].substr(0, l);
    }
};