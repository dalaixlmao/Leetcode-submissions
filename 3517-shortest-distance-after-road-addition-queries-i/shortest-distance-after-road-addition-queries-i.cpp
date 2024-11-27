class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> g(n);

        for (int i = 0; i < n - 1; i++) {
            g[i].push_back(i + 1);
        }
        vector<int> dis(n);
        for (int i = 0; i < n; i++) {
            dis[i] = i;
        }
        int mn = n - 1;
        vector<int> ans;
        for (int i = 0; i < q.size(); i++) {
            int x = q[i][0];
            int y = q[i][1];
            g[x].push_back(y);
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            pq.push({0, 0});
            int flag = 0;

            while (!pq.empty()) {
                int lev = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if (node == n - 1) {
                    mn = min(mn, lev);
                    break;
                }
                for (auto j : g[node]) {
                    if (dis[j] >= lev + 1) {
                        dis[j] = lev + 1;
                        pq.push({dis[j], j});
                    }
                }
            }
            ans.push_back(mn);
        }
        return ans;
    }
};