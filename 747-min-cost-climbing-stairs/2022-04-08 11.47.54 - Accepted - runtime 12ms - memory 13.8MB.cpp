class Solution {
public:
    int dp[10001];
    int solve(int i,vector<int>&cost,int n)
    {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = min(solve(i+1,cost,n),solve(i+2,cost,n)) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // memset(dp , -1 , sizeof(dp));
        // return min(solve(0,cost,n),solve(1,cost,n));
        
        vector<int>dp(n+2);
        dp[n] = 0;
        dp[n+1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            dp[i] = min(dp[i+1],dp[i+2]) + cost[i];
        }
        return min(dp[0],dp[1]);
    }
};