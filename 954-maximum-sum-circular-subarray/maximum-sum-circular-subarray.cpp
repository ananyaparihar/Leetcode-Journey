class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        //max subarray sum (Kadane)
        int maxEnd = nums[0];
        int maxRes = nums[0];

        for (int i = 1; i < n; i++) {
            maxEnd = max(nums[i], maxEnd + nums[i]);
            maxRes = max(maxRes, maxEnd);
        }

        //Min subarray sum 
        int minEnd = nums[0];
        int minRes = nums[0];

        for (int i = 1; i < n; i++) {
            minEnd = min(nums[i], minEnd + nums[i]);
            minRes = min(minRes, minEnd);
        }

        // Sum of full array
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum == minRes) {                // All numbers negative case
            return maxRes;
        }
        int circular = sum - minRes;        // Circular case
        return max(maxRes, circular);
    }
};

