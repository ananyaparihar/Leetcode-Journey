class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int guess = low + (high - low) / 2;

            // Target found
            if(nums[guess] == target) {
                return true;
            }

            // Cannot determine which half is sorted
            if(nums[low] == nums[guess] && nums[guess] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if(nums[low] <= nums[guess]) {

                // Target lies in left sorted half
                if(nums[low] <= target && target < nums[guess]) {
                    high = guess - 1;
                }
                else {
                    low = guess + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in right sorted half
                if(nums[guess] < target && target <= nums[high]) {
                    low = guess + 1;
                }
                else {
                    high = guess - 1;
                }
            }
        }

        return false;
    }
};