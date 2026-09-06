class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int res=INT_MIN;
        unordered_map<char,int>m;
        for(high=0;high<s.size();high++){
            m[s[high]]++;
            int k=high-low+1;
            while(m.size()<k){
                m[s[low]]--;
                if(m[s[low]]==0){
                    m.erase(s[low]);
                }
                low++;
                k=high-low+1;
            }
            int len=high-low+1;
            res=max(res,len);
           
        }
        if(res==INT_MIN){
            return 0;
        }
        return res;
        
    }
};