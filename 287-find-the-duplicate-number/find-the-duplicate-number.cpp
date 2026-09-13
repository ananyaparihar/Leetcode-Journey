class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int slow=nums[0],fast=nums[0];
         do{
            slow=nums[slow];//+!
            fast=nums[fast];
            fast=nums[fast];//+2
         }
         while (slow!=fast);
         slow=nums[0];
         while(slow!=fast){
            slow=nums[slow];//+!
            fast=nums[fast];//+1

         }
         return fast;
    }
};