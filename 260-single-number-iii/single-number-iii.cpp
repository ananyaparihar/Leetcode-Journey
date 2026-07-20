class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;

        for (int x : nums)
            xorr ^= x;

        unsigned int rightmost =
            (unsigned int)xorr & -(unsigned int)xorr;

        int b1 = 0, b2 = 0;

        for (int x : nums) {
            if ((unsigned int)x & rightmost)
                b1 ^= x;
            else
                b2 ^= x;
        }

        return {b1, b2};
    }
};