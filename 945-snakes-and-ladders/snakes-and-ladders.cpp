class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // return 0;
        for (int i = 0; i < n; i++)
            if ((n - i) % 2 == 0)
                reverse(board[i].begin(), board[i].end());
        reverse(board.begin(), board.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        if (board.back().back() != -1)
            return -1;
        q.push({0, 1});

        map<int, int> ind;
        int mx = INT_MIN;
        vector<int> pfmax;
        for (int i = 0; i < n * n; i++) {
            int r = i / n;
            int c = i % n;
            if (board[r][c] > i + 1) {
                mx = max(mx, board[r][c]);
            } else
                mx = max(mx, i + 1);
            pfmax.push_back(mx);
        }
        vector<int> vis(n * n, 0);
        vis[0] = 1;
        while (!q.empty()) {
            int steps = q.top().first;
            int cell = q.top().second;
            cout << cell << " " << steps << endl;
            q.pop();
            if (cell == n * n)
                return steps;
            if (n * n < steps)
                return -1;
            int c = 0;
            int flag = 0;
            for (int j = 1; j <= min(n * n - cell, 6); j++) {
                int ncell = cell + j;
                int r = (ncell - 1) / n;
                int c = (ncell - 1) % n;
                if (board[r][c] == -1 || board[r][c] > cell)
                    flag = 1;
                if (!vis[ncell - 1]) {
                    vis[ncell-1] = 1;
                    if (board[r][c] != -1)
                        q.push({steps + 1, board[r][c]});
                    else
                        q.push({steps + 1, ncell});
                }
            }
            cout << flag << endl;
            if (!flag) {

                int x = ((board[(cell - 1) / n][(cell - 1) % n] == -1)
                             ? cell
                             : board[(cell - 1) / n][(cell - 1) % n]);
                cout << pfmax[cell - 1] << " " << x << endl;
                if (pfmax[cell - 1] <= x)
                    return -1;
            }
        }
        return -1;
    }
};