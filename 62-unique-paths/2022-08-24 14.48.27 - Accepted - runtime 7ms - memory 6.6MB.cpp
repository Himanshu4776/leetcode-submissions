class Solution {
public:
    bool boundaryCross(int i,int j, int m, int n) {
        if(i<0 || j< 0 || i>= m || j>=n) return true;
        return false;
    }
    
    int solve(int i, int j, int m, int n, vector<vector<int>>&dp)
    {
        // Boundary check
        if(boundaryCross(i,j,m,n) == true) return 0;
        
        // Memoizatrion check
        if(dp[i][j] != -1) return dp[i][j];
        
        // Destination check
        if(i == m-1 && j == n-1) return 1;
        
        dp[i][j] = solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp);
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
        
        // Top down approach:
//         vector<vector<int>>dp(m,vector<int>(n,0));
//         // make row1 and col1 == 1
//         for (int i = 0; i < m; ++i) {
//             dp[i][0] = 1;
//         }
//         for (int i = 0; i < n; ++i) {
//             dp[0][i] = 1;
//         }

//         // now let's apply the bottom-up approach 
//         // for values more than 1.
//         for (int i = 1; i < m; i++)
//         {
//             for (int j = 1; j < n; j++)
//             {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }

//         return dp[m-1][n-1];
    }
};