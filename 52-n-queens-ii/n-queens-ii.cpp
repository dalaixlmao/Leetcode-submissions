class Solution {
public:
    bool safe(int i, int j, vector<vector<int>>& g) {
        int n = g.size();
        if (i < 0 || j < 0 || j >= n || i >= n)
            return false;
        for (int ii = 0; ii <= i; ii++) {
            if (g[ii][j])
                return false;
        }

        for (int jj = 0; jj <= j; jj++) {
            if (g[i][jj])
                return false;
        }
        int ti = i, tj = j;
        while (i >= 0 && j >= 0) {
            if (g[i][j])
                return false;
            i--;
            j--;
        }
        i = ti, j = tj;
        while (i >= 0 && j < n) {
            if (g[i][j])
                return false;
            i--;
            j++;
        }

        return true;
    }

    int f(int i, int j, vector<vector<int>>& g) {
        cout << i << " " << j << endl;
        if (safe(i, j, g)) {
            int n = g.size();
            if (i == n - 1)
                return 1;
            int s = 0;
            g[i][j] = 1;
            for (int k = 0; k < n; k++) {
                s += f(i + 1, k, g);
            }
            g[i][j] = 0;
            return s;
        }
        return 0;
    }

    int totalNQueens(int n) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += f(0, i, g);
        }
        return s;
    }
};