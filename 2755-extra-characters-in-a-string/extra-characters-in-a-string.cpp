class Solution {
public:

    int f(int i, int j, string &s, map<string, int> &exist, vector<vector<int>> &dp)
    {
        // cout<<i<<" "<<j<<endl;
        if(j>=s.size())
        return 0;
        if(i>j)
        return 0;
        if(i>=s.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int n=s.size();
        string t = s.substr(i, j-i+1);
        int mx=f(i+1, j+1, s, exist, dp);
        // cout<<t<<endl;
        if(exist[t])
        {
            mx=max(mx, j-i+1 + f(j+1, j+1, s, exist, dp));
        }
        for(int k=j+1;k<n;k++)
        {
          t+=s[k];
        //   cout<<t<<" ";
          if(exist[t])
          mx=max(mx,k-i+1+f(k+1, k+1, s, exist, dp));
        }
        // cout<<endl;
        return dp[i][j]=mx;
    }


    int minExtraChar(string s, vector<string>& dictionary) {
        map<string, int> exist;
        int n=dictionary.size();
        for(int i=0;i<n;i++)
        {
            exist[dictionary[i]]=1;
        }
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, -1));
        int p = f(0, 0, s, exist, dp);
        return s.size()-p;
    }
};