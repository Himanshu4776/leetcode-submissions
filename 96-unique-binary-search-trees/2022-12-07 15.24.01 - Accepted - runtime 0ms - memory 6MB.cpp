class Solution {
public:
    int solve(int d,vector<int>&dp) {
        if(d <= 1) return 1;

        if(dp[d] != -1) return dp[d];

        int ans = 0;
        for(int i=1;i<=d;i++)
        {
            // making i the root node and checking permutations
            ans += solve(i-1,dp)*solve(d-i,dp);
        }
        return dp[d] = ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};