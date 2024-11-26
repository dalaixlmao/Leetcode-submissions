class Solution {
public:
    int findChampion(int n, vector<vector<int>>& e) {
        int m = e.size();
        vector<int> indeg(n, 0);
        for (int i = 0; i < m; i++) {
            indeg[e[i][1]]++;
        }
        int c = 0;
        int ans;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                c++;
                ans = i;
            }
        }
        if (c > 1)
            return -1;
        return ans;
    }
};