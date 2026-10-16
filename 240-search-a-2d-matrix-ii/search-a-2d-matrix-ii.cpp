class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int m=a.size();//row
        int n=a[0].size();//column
        int r=m-1;
        int c=0;
        while(r>=0 && c<=n-1){
            if(a[r][c]==target){
                return true;
            }else if(a[r][c]>target){
                r--;
            }else{
                c++;
            }
        }
        return false;
    }
};