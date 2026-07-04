class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
       int score=0;
       int counter=0;
       int i=0;
       while(i<events.size() && counter!=10){
          if (events[i]=="W" ){
            counter+=1;
          }
          else if(events[i]=="WD" || events[i]=="NB"){
            score+=1;
          }
          else{
            score+=stoi(events[i]);
          }
          i++;

       }
       vector<int> ans = {score, counter};
       return ans;
    }
};