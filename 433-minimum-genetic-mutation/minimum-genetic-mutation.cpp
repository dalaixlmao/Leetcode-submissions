class Solution {
public:
    string g = "ATGC";
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> st;
        int n = bank.size();
        for (int i = 0; i < n; i++) {
            st[bank[i]]=i;
        }
        unordered_map<char, int> ind = {
            {'A', 0},
            {'T', 1},
            {'G', 2},
            {'C', 3},
        };
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
        pq.push({0, startGene});
        unordered_map<string, int> vis;
        vis[startGene] = 1;
        while(!pq.empty())
        {
            string node = pq.top().second;
            int lev = pq.top().first;
            pq.pop();

            if(node == endGene)
            return lev;

            for(int i=0;i<node.size();i++)
            {
                char org = node[i];
                for(int j=1;j<=3;j++)
                {
                    int newInd = (ind[node[i]]+j)%4;
                    node[i] = g[newInd];
                    if(st.count(node) && !vis.count(node))
                    {
                        vis[node]=1;
                        pq.push({lev+1, node});
                    }
                }
                node[i] = org;
            }
        }
        return -1;
    }
};