class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replace = 0;

        for (int it = 0; it < nums.size(); it++) {

            if (replace < 2 || nums[it] != nums[replace - 2]) {
                nums[replace] = nums[it];
                replace++;
            }
        }

        return replace;
    }
};