class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>freq;
        for(auto i:arr){
            freq[i]++;
        }
        int uniquecount=0;
        string result="-1";
        for(int i=0;i<arr.size();i++){
            if(freq[arr[i]]==1){
                uniquecount++;
                if(uniquecount == k){
                    return arr[i];
                }
            }

        }
        return "";
    }
};