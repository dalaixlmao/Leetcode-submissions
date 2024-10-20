class Solution {
public:
    vector<int> x = {1, -1, 0, 0, 1, -1, 1,-1};
    vector<int> y = {0, 0, 1, -1, -1, 1, 1,-1};
    bool isSafe(int a, int b, int n, int m) {
        return (a >= 0 && b >= 0 && a < n && b < m);
    }

    void gameOfLife(vector<vector<int>>& b) {
        map<pair<int, int>, int> live, dead;
        int n = b.size();
        int m = b[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = 0;
                int z = 0, o = 0;
                for (int k = 0; k < 8; k++) {
                    int nr = i + x[k];
                    int nc = j + y[k];
                    if (isSafe(nr, nc, n, m)) {
                        if (b[nr][nc])
                            o++;
                        else
                            z++;
                    }
                }
                if(b[i][j] && (o<2 || o>3))
                {
                    dead[{i,j}]++;
                }
                if(!b[i][j] && o==3)
                {
                    live[{i,j}]++;
                }
            }
        }

        for(auto i:live)
        b[i.first.first][i.first.second]=1;
        for(auto i:dead)
        b[i.first.first][i.first.second]=0;
    }
};