class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_end=nums[0];
        int max_ans=INT_MIN;

        int min_end=nums[0];
        int min_ans=INT_MAX;

        int res=abs(nums[0]);
        for(int i=1;i<nums.size();i++){
            int v1 = max_end + nums[i];
            int v2 = nums[i];

            max_end = max(v1, v2);
            max_ans = max(max_ans, max_end);

            int v3 = min_end + nums[i];
            int v4 = nums[i];

            min_end = min(v3, v4);
            min_ans = min(min_ans, min_end);

            res = max(res, max(abs(max_ans), abs(min_ans)));
        }
        return res;
    }
};