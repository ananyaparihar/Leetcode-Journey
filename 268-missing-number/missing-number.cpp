class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int expsum= n*(n+1)/2;
        int actualsum=0;
        for(int x:nums){
            actualsum+=x;
        }
        return expsum-actualsum;
    }
};