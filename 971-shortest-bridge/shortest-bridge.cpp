class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};

    bool isSafe(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size();
        queue<pair<int, pair<int, int>>> qq;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1 && flag == 0) {
                    qq.push({0, {i, j}});
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    g[i][j] = 2;
                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = r + x[k];
                            int nc = c + y[k];
                            if (isSafe(nr, nc, n) && g[nr][nc] == 1) {
                                g[nr][nc] = 2;
                                qq.push({0, {nr, nc}});
                                q.push({nr, nc});
                            }
                        }
                    }
                    flag = 1;
                    break;
                }
                if (flag)
                    break;
            }
        }

        while (!qq.empty()) {
            int d = qq.front().first;
            int r = qq.front().second.first;
            int c = qq.front().second.second;
            qq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + x[i];
                int nc = c + y[i];
                if (isSafe(nr, nc, n) && g[nr][nc] <= 1) {
                    if (g[nr][nc] == 1)
                        return d;
                    g[nr][nc] = 3;
                    qq.push({d + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};