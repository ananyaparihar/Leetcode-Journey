class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=0;
        int product=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                product=(nums[i]-1)*(nums[j]-1);
                if(product>max){
                    max=product;
                }
            }
        }
        return max;
    }
};