class Solution {
public:

    bool fun(unordered_map<char,int> &have,
             unordered_map<char,int> &need)
    {
        for(auto x : need)
        {
            if(have[x.first] < x.second)
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        unordered_map<char,int> have;
        unordered_map<char,int> need;

        if(n < m)
            return "";

        for(int i=0; i<m; i++)
        {
            need[t[i]]++;
        }

        int low = 0;
        int high = 0;

        int res = INT_MAX;
        int start = -1;

        for(high=0; high<n; high++)
        {
            have[s[high]]++;

            while(fun(have, need))
            {
                int len = high-low+1;

                if(res > len)
                {
                    res = len;
                    start = low;
                }

                have[s[low]]--;
                low++;
            }
        }

        if(res == INT_MAX)
            return "";

        return s.substr(start,res);
    }
};