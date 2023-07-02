class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // int val,n = nums.size();
        // stack<int>st;
        // st.push(nums[0]);
        // for (int i = 0; i < n; ++i)
        // {
        //     if(st.size() < k)
        //     {
        //         st.push(nums[i]);
        //     }
        //     while(st.top() > nums[i] && st.size() > k && (n-i-1)>=(k-st.size()))
        //     {
        //         st.pop();
        //     }
        // }
        // // Now Return it.
        // vector<int>ans;
        // while(!st.empty())
        // {
        //     val = st.top();
        //     ans.push_back(val);
        //     st.pop();
        // }
        // return ans;
        vector<int> stack;
        int nums_to_delete = nums.size()-k;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!stack.empty() && nums[i] < stack.back() && nums_to_delete)
            {
                stack.pop_back();
                nums_to_delete--;
            }
            stack.push_back(nums[i]);
        }
        return vector<int>(stack.begin(), stack.begin()+k);
    }
};