class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int>dq;
        int i=0, n = nums.size();
        while(i<k) {
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                // as we already storing indices so we can do nums[dq.back()]
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        // window limit reached now iterate after till n length
        while(i<n) {
            ans.push_back(nums[dq.front()]);

            while(dq.front() <= (i-k) && !dq.empty()) {
                // mantaining size of window and keep max values in dq for size k
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[i]>=nums[dq.back()]) {
                // removing values saller to current element
                dq.pop_back();
            }

            dq.push_back(i);
            i++;
        }
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};
