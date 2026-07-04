class Solution {
public:
    int passwordStrength(string password) {
        int n=password.size();
        unordered_set<char> unique;
        for(auto i:password){
            unique.insert(i);
        }
        int ans=0;
        for(auto i: unique){
            char c=i;
            if (c>=97 && c<=122){
                ans+=1;
            }
            if(c>=65 && c<=90){
                ans+=2;
            }
            if(isdigit(c)){
                ans+=3;
            }
            if(c=='!' || c=='@' || c=='#' || c=='$'){
                ans+=5;
            }
        }
        return ans;
    }
};