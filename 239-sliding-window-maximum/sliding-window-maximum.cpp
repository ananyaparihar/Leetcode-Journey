class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> maximum;

        deque<int> dq;

        for(int i = 0; i < n; i++) {

            // Remove elements outside the window
            while(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current element
            dq.push_back(i);

            // Start storing answers when first window is complete
            if(i >= k-1) {
                maximum.push_back(nums[dq.front()]);
            }
        }

        return maximum;
    }
};