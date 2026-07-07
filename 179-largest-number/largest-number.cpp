class Solution {
public:
    // Custom comparator
    static bool cmp(string &a, string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        // Convert integers to strings
        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        // Sort using our comparator
        sort(arr.begin(), arr.end(), cmp);

        // Edge case: if largest element is 0
        if (arr[0] == "0")
            return "0";

        // Join all strings
        string ans = "";

        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};