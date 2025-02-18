class dsu {
public:
    vector<int> par;

public:
    dsu(int n) {
        for (int i = 0; i < n; i++)
            par.push_back(i);
    }

    int findPar(int n) {
        if (par[n] == n)
            return n;
        return par[n] = findPar(par[n]);
    }

    void unionSet(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        par[pu] = pv;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        unordered_map<string, int> nameHash;
        unordered_map<string, int> emailHash;
        unordered_map<int, int> email_to_name;
        // cout<<"hi1"<<endl;
        for (int i = 0; i < n; i++) {
            cout << a[i][0] << endl;
            nameHash[a[i][0]] = i;
        }
        int ind = 0;
        dsu ds(n);
        cout << "hi" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < a[i].size(); j++) {
                if (!emailHash.count(a[i][j]))
                    emailHash[a[i][j]] = ind++;
                else {
                    ds.unionSet(i, email_to_name[emailHash[a[i][j]]]);
                }
                email_to_name[emailHash[a[i][j]]] = i;
            }
        }
        for (auto i : email_to_name) {
            cout << i.first << " " << i.second << endl;
        }
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[ds.findPar(i)].insert(i);
        }
        vector<vector<string>> ans;
        for (auto i : mp) {
            set<string> x;
            int ind = i.first;
            for (auto j : i.second) {
                for (int k = 1; k < a[j].size(); k++) {
                    x.insert(a[j][k]);
                }
            }
            vector<string> p;
            p.push_back(a[ind][0]);
            for (auto i : x)
                p.push_back(i);
            ans.push_back(p);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};