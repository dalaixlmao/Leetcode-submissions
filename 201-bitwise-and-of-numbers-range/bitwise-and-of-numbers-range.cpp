class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int bl = (left >> i) & 1;
            int br = (right >> i) & 1;
            if (bl != br)
                continue;
            else {
                if (bl == 1) {
                    if (left/(1<<(i+1))==right/(1<<(i+1))) {
                        ans |= (1 << i);
                    }
                }
            }
        }
        return ans;
    }
};