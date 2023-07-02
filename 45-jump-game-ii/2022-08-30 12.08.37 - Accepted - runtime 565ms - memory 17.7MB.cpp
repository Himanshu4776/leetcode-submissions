class Solution {
public:
    // Memoization:
    long long int f(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(i >= n-1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        long long int res = INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
            res = min(res, 1+f(i+j,n,nums,dp));
        }
        return dp[i] = res;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1,-1);
        // return f(0,n,nums,dp);
        
        // iterative:
        vector<long long int>dp(n,100001);
        dp[n-1] = 0;
        // start from n-2 as n-1 is ending point and it is 0 already.
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<=nums[i];j++)
            {
                dp[i] = min(dp[i],1 + dp[min(n-1,i+j)]);
                    // min is used in dp[min()] for handling bounds like [0] and n<3
            }
        }
        return dp[0];
    }
    // One more better approach is there using BFS. read it
};