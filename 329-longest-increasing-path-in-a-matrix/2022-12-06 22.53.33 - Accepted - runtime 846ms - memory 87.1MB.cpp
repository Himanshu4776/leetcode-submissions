class Solution {
public:
    int N,M;
    vector<vector<int>>dp;
    bool boundarycheck(int i, int j) {
        if(i >= N || j>= M || i < 0 || j < 0) return false;
        return true;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix) {
        if(dp[x][y] != 0) return dp[x][y];
        
        vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int ans = 1;
        for(int i=0;i<4;i++){
            int X = x + dir[i][0];
            int Y = y + dir[i][1];
            // boundary check
            if(boundarycheck(X,Y) == false) continue;
            // value check
            if(matrix[x][y] >= matrix[X][Y] ) continue;

            //Valid path can be counted for possible answer path
            ans = max(ans, 1 + dfs(X,Y,matrix));
        }
        return dp[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0) return 0;

        N = n;
        M = m;
        dp=vector<vector<int>>(n,vector<int>(m,0));
        int res = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res = max(res, dfs(i,j,matrix)); 
            }
        }
        return res;
    }
};