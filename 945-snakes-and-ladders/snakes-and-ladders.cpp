class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++)
            if ((n - i) % 2 == 0)
                reverse(board[i].begin(), board[i].end());
        reverse(board.begin(), board.end());
        queue<pair<int, int>> q;
        if (board.back().back() != -1)
            return -1;
        q.push({0, 1});
        vector<int> vis(n * n, 0);
        vis[0] = 1;
        while (!q.empty()) {
            int steps = q.front().first;
            int cell = q.front().second;
            q.pop();
            if (cell == n * n)
                return steps;
            if (n * n < steps)
                return -1;
            int c = 0;
            for (int j = 1; j <= min(n * n - cell, 6); j++) {
                int ncell = cell + j;
                int r = (ncell - 1) / n;
                int c = (ncell - 1) % n;
                if (!vis[ncell - 1]) {
                    vis[ncell-1] = 1;
                    if (board[r][c] != -1)
                        q.push({steps + 1, board[r][c]});
                    else
                        q.push({steps + 1, ncell});
                }
            }
        }
        return -1;
    }
};