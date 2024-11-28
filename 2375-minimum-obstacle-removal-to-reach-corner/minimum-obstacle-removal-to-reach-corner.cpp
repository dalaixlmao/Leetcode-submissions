class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int minimumObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0, {0, 0}});
        vector<vector<int>> obs(n, vector<int>(m, INT_MAX));
        obs[0][0] = 0;
        while (!q.empty()) {
            int r = q.top().second.first;
            int c = q.top().second.second;
            int ob = q.top().first;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + x[i];
                int nc = c + y[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    obs[nr][nc] > ob + g[nr][nc]) {
                    obs[nr][nc] = ob + g[nr][nc];
                    q.push({obs[nr][nc], {nr, nc}});
                }
            }
        }

        return obs[n - 1][m - 1];
    }
};