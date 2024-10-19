class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        int count = 0;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = n - 1;
        while (j<n && nums[j] != val) {
            j++;
        }
        if (j >= n) {
            return n;
        }
        while (i>=0 && nums[i] == val) {
            count++;
            i--;
        }
        if (i < 0) {
            return 0;
        }
        while (i > j) {
            if (nums[i] != val) {
                int temp = j;
                swap(nums[i], nums[j]);
                while (nums[i] == val) {
                    count++;
                    i--;
                }
                while (nums[j] != val)
                    j++;
            } else {
                i--;
            }
        }
        return n - count;
    }
};