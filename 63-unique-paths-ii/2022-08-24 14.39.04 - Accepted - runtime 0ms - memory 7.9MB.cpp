class Solution {
public:
    bool obstacle(int i, int j, vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[i][j] == 1) return true;
        return false;
    }
    
    bool boundaryCross(int i, int j, vector<vector<int>>& obstacleGrid) {
        if( i < 0 || j < 0 || i >= obstacleGrid.size() || j >= obstacleGrid[0].size())
            return true;
        
        return false;
    }
    
    // brute force solution
    int solve(int i, int j, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        // Boundary case
        if(boundaryCross(i,j,obstacleGrid)) return 0;
        
        // Obstacle case
        if(obstacleGrid[i][j] == 1) return 0;
        
        // Destination case
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1 
           && !obstacleGrid[i][j]) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = solve(i,j+1,obstacleGrid,dp) + solve(i+1,j,obstacleGrid,dp);
        return dp[i][j];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans = 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,obstacleGrid,dp);
    }
};