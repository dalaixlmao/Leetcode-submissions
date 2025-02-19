class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        unordered_set<int> st;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }
        int mx = 0;
        for (auto i : st) {
            if (st.count(i - 1))
                continue;
            else {
                int x = i;
                while (st.count(x + 1))
                    x++;

                mx=max(mx, x-i+1);
            }
        }
        return mx;
    }
};