class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int cur=k;
        while(s.count(cur)){
            cur+=k;
        }
        return cur;

    }
};