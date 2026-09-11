class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0;
        double avg=0;
        double maximum=INT_MIN;
        for(int i=0;i<k;i++){
            sum=sum+arr[i];
        }
        avg=(double)sum/k;
        maximum=max(avg,maximum);
        int low=0;
        int high=k-1;
        while(high<n){
            sum=sum-arr[low];
            low++;
            high++;
            if(high==n)break;
            sum=sum+arr[high];
            avg=(double)sum/k;
            maximum=max(maximum,avg);
        }
        return maximum;
    }
};