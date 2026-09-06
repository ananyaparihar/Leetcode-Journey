class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int high=0;
        int res=INT_MIN;
        unordered_map<int,int>m;
        for(high=0;high<fruits.size();high++){
            m[fruits[high]]++;
            while(m.size()>2){
                m[fruits[low]]--;
                if(m[fruits[low]]==0){
                    m.erase(fruits[low]);
                }
                low++;
            }
            int l=high-low+1;
            res=max(res,l);

        }
        return res;
    }
};