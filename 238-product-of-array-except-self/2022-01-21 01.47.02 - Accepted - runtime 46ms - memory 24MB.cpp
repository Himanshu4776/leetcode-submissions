class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // using 2 more arrays
        // vector<int>ans(n,1);
        // vector<int>pre(n,1);
        // vector<int>post(n,1);
        // for(int i=1;i<n;i++)
        // {
        //     pre[i] = pre[i-1]*nums[i-1];
        // }
        // for(int i=n-1;i>=1;i--)
        // {
        //     post[i-1] = post[i]*nums[i];
        // }
        // for(int i=0;i<n;i++)
        // {
        //     ans[i] = pre[i]*post[i];
        // }
        // return ans;
        
        vector<int>ans(n,1);
        for(int i=1;i<n;i++)
        {
            ans[i] = ans[i-1]*nums[i-1];
        }
        int right = 1;
        for(int i=n-1;i>0;i--)
        {
            right = right*nums[i];
            ans[i-1] = ans[i-1]*right;
        }
        return ans;
    }
};