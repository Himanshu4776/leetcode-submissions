class Solution {
public:
    bool jump(int i, int n, vector<int>&nums, vector<int>&dp)
    {
        if( i == n-1) return true;
        if(i > n-1) return false;
        
        if(dp[i] != -1) return dp[i];
        
        for(int j=1;j<=nums[i];j++)
        {
            // if recurring from here gives true anytime then we can return true
            // else false is by default
            if(jump(i+j,n,nums,dp) == true) {
                return true;
            }
        }
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return jump(0,n,nums,dp);
    }
};