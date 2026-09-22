class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
        
        vector<vector<int>> res;

        sort(a.begin(), a.end());

        for(int i = 0; i < a.size(); i++) {

            // Case 1: current interval is completely before newInterval
            if(a[i][1] < newInterval[0]) {
                res.push_back(a[i]);
            }

            // Case 2: current interval is completely after newInterval
            else if(a[i][0] > newInterval[1]) {
                res.push_back(newInterval);

                // Add all remaining intervals
                for(int j = i; j < a.size(); j++) {
                    res.push_back(a[j]);
                }

                return res;
            }

            // Case 3: intervals are overlapping
            else {
                newInterval[0] = min(newInterval[0], a[i][0]);
                newInterval[1] = max(newInterval[1], a[i][1]);
            }
        }

        // If newInterval wasn't inserted yet
        res.push_back(newInterval);

        return res;
    }
};