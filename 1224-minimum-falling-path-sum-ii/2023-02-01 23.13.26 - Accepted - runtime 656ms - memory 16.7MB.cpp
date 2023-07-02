class Solution {
public:
    long int solve(int i, int j,int n,vector<vector<int>>& grid,vector<vector<long int>>&dp) {
        if(j< 0|| j >= n) return INT_MAX;
        if(i == n) return 0;

        if(dp[i][j] != -100) return dp[i][j];

        long int val = INT_MAX;
        for(int d=0;d<n;d++) {
            if(d != j) {
                val = min(val, solve(i+1,d,n,grid,dp));
            }
        }
        
        return dp[i][j] = (grid[i][j] + val);
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long int>>dp(n,vector<long int>(n,-100));
        if(n==1) return grid[0][0];
        
        long int ans = INT_MAX;
        for(int j=0;j<n;j++) {
            ans = min(ans,solve(0,j,n,grid,dp));
        }

        return ans;
    }
};