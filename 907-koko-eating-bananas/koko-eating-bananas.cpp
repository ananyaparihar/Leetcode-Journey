class Solution {
public:
    long long helper(vector<int>&piles,int n,int speed){
        long long h=0;
        if(speed==0){
            return -1;
        }else{
        for(int i=0;i<piles.size();i++){
            h=h+piles[i]/speed;
            if(piles[i]%speed!=0){
                h++;
            }
        }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=1;
        int high=piles[n-1];
        int res=-1;
        while(low<=high){
            int guess=low+(high-low)/2;
            long long hour=helper(piles,n,guess);
            if(hour>h){
                low=guess+1;
            }else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};