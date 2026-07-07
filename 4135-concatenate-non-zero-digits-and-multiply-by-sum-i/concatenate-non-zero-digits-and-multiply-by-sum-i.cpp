class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        for (char i: to_string(n)){
            
            if(i!='0'){
                x=x*10+i-'0';
                sum=sum+i-'0';
                

            }
        
        }
        return x*sum;
    }
};