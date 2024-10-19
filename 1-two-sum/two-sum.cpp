class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> x;
        for (int i = 0; i < n; i++) {
            if (x.count(target - nums[i])) {
                return {x[target - nums[i]], i};
            }
            x[nums[i]] = i;
        }
        return {};
    }
};