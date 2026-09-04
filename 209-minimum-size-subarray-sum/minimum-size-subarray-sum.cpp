class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int low=0;
        int high=0;
        int n=arr.size();
        int sum=0;
        int minlength=INT_MAX;
        while(high<n){
            sum+=arr[high];
            while(sum>=target){
                minlength=min(minlength,high-low+1);
                sum=sum-arr[low];
                low++;
            }
            high++;
        }
        return (minlength == INT_MAX) ? 0 : minlength;

    }
};