class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        vector<string> ans;
        if(a.size()==0)
        return ans;
        int l = a[0], r = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1] + 1) {
                r = a[i];
            } else {
                if (l == r)
                    ans.push_back(to_string(l));
                else
                    ans.push_back(to_string(l) + "->" + to_string(r));
                l = a[i];
                r = a[i];
            }
        }
        if (l == r)
            ans.push_back(to_string(l));
        else
            ans.push_back(to_string(l) + "->" + to_string(r));

        return ans;
    }
};