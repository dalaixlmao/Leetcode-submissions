class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t s = 0;
        for (int i = 0; i < 32; i++) {
            s = 2 * s + n % 2;
            n = n >> 1;
        }
        return s;
    }
};