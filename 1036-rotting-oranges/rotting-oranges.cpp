class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};

    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 2) {
                    q.push({0, {i, j}});
                    dis[i][j] = 0;
                    while (!q.empty()) {
                        int r = q.front().second.first;
                        int c = q.front().second.second;
                        int d = q.front().first;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = r + x[k];
                            int nc = c + y[k];
                            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                                g[nr][nc] == 1 && dis[nr][nc] > d + 1) {
                                dis[nr][nc] = d + 1;
                                q.push({d + 1, {nr, nc}});
                            }
                        }
                    }
                }
            }
        }

        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1 && dis[i][j] == INT_MAX)
                    return -1;
                else if (g[i][j] == 1 && dis[i][j] != INT_MAX) {
                    mx = max(mx, dis[i][j]);
                }
            }
        }
        return mx;
    }
};