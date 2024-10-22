class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& ni) {

        int l = ni[0], r = ni[1];
        int n = intervals.size();
        vector<vector<int>> ans;
        if (intervals.empty()) {
            ans.push_back({l, r});
            return ans;
        }
        if (r < intervals[0][0]) {
            ans.push_back({l, r});
            for (auto i : intervals)
                ans.push_back(i);
            return ans;
        }
        int pushed = 0;
        for (int i = 0; i < n; i++) {
            if (!pushed) {
                if (intervals[i][1] < l) {
                    ans.push_back(intervals[i]);
                } else {
                    pushed = 1;
                    if (intervals[i][0] > r) {
                        ans.push_back({l, r});
                        ans.push_back(intervals[i]);
                    } else
                        ans.push_back(
                            {min(intervals[i][0], l), max(intervals[i][1], r)});
                }
            } else {
                if (intervals[i][0] > ans.back()[1]) {
                    ans.push_back(intervals[i]);
                } else {
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }
            }
        }
        if (pushed == 0) {
            ans.push_back({l, r});
        }

        return ans;
    }
};