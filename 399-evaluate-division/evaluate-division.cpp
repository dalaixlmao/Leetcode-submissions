class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        map<string, vector<pair<double, string>>> g;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string x = equations[i][0];
            string y = equations[i][1];
            double val = values[i];
            g[x].push_back({val, y});
            g[y].push_back({1.0 / val, x});
        }
        map<string, map<string, double>> dis;
        for (auto i : g) {
            string currNode = i.first;
            queue<pair<double, string>> q;
            q.push({1.0, currNode});
            dis[currNode][currNode] = 1.0;
            while (!q.empty()) {
                string node = q.front().second;
                double val = q.front().first;
                q.pop();
                for (auto ch : g[node]) {
                    double w = ch.first;
                    string child = ch.second;
                    if (!dis[currNode].count(child)) {
                        dis[currNode][child] = val * w;
                        cout << currNode << " " << child << " " << val * w
                             << endl;
                        q.push({val * w, child});
                    }
                }
            }
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            if (!dis.count(a)) {
                ans.push_back(-1.0);
            } else if (!dis[a].count(b)) {
                ans.push_back(-1.0);
            } else
                ans.push_back(dis[a][b]);
        }
        return ans;
    }
};