class Solution {
public:
    int dp[1000009];
    int solve(int x,vector<int>&arr,int n)
    {
        if(x < 0) return 10000000;
        if(x == 0) return 0;

        if(dp[x] != -1) return dp[x];

        int res = 10000000;
        for (int i = 0; i < n; ++i)
        {
            if(x >= arr[i]) {
                res = min(res,solve(x-arr[i],arr,n));
            }
        }

        return dp[x] = 1+res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        int ans = solve(amount,coins,n);
        if(ans <= 10000000) return ans;
        return -1;
    }
};