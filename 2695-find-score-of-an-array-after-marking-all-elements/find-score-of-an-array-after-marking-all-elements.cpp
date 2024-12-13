class Solution {
public:
#define ll long long
    long long findScore(vector<int>& arr) {
        int n = arr.size();
        map<int, map<int, int>> ind;
        for (int i = 0; i < n; i++) {
            ind[arr[i]][i] = 1;
        }

        ll i = 0LL;
        ll sm = 0LL;
        while (ind.size() != 0) {
            while (!ind.count(i)) {
                i++;
            }
            sm += i;
            int firstInd = (*ind[i].begin()).first;
            ind[i].erase(firstInd);
            if (ind[i].size() == 0) {
                ind.erase(i);
            }
            int prv = firstInd - 1;
            if (prv >= 0) {
                int el = arr[prv];
                if (ind.count(el) && ind[el].count(prv)) {
                    ind[el].erase(prv);
                    if (ind[el].size() == 0)
                        ind.erase(el);
                }
            }
            int nxt = firstInd + 1;
            if (nxt < n) {
                int el = arr[nxt];
                if (ind.count(el) && ind[el].count(nxt)) {
                    ind[el].erase(nxt);
                    if (ind[el].size() == 0)
                        ind.erase(el);
                }
            }
        }
        return sm;
    }
};