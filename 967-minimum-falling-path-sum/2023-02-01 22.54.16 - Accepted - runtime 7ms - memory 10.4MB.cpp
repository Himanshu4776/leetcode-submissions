class Solution {
public:
    int solve(int i, int j,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        if(j< 0|| j >= n) return INT_MAX;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ch1 = solve(i+1,j-1,n,matrix,dp);
        int ch2 = solve(i+1,j,n,matrix,dp);
        int ch3 = solve(i+1,j+1,n,matrix,dp);

        return dp[i][j] = (matrix[i][j] + min(ch1,min(ch2,ch3)));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        
        // int ans = INT_MAX;
        // for(int j=0;j<n;j++) {
        //     ans = min(ans,solve(0,j,n,matrix,dp));
        // }

        // return ans;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        // Initializing first row - base condition
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0;j<m;j++){
                
                int up = matrix[i][j] + dp[i-1][j];
                
                int leftDiagonal= matrix[i][j];
                if(j-1>=0) leftDiagonal += dp[i-1][j-1];
                else leftDiagonal += 1e9;
                
                int rightDiagonal = matrix[i][j];
                if(j+1<m) rightDiagonal += dp[i-1][j+1];
                else rightDiagonal += 1e9;
                
                dp[i][j] = min(up, min(leftDiagonal,rightDiagonal));
                
            }
        }
        
        int mini = INT_MAX;
        
        for(int j=0; j<m;j++){
            mini = min(mini,dp[n-1][j]);
        }
        
        return mini;
    }
};