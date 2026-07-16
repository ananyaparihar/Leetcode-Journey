class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum=0;
        for(int i: nums){
            m[i]++;
        }
        for(auto p: m){
            if(p.second==1){
                sum+=p.first;
            }
        }
        return sum;
    }
};