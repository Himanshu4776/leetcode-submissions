class Solution {
public:
    int f(string s, string p, int i, int j, vector<vector<int>>&dp)
    {
        // base case
        if(i < 0 && j < 0) return 0;
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        //check if value already present
        if(dp[i][j] != -1) return dp[i][j];
        
        // same character
        if(s[i] == p[j]) return dp[i][j] = f(s,p,i-1,j-1,dp);

        // repalce
        int op1 = 1 + f(s,p,i-1,j-1,dp);
        // remove
        int op2 = 1 + f(s,p,i,j-1,dp);
        // add
        int op3 = 1 + f(s,p,i-1,j,dp);

        return dp[i][j] = (min(op1, min(op2,op3)));
    }
    
    int minDistance(string s, string p) {
        int n = s.size();
        int m = p.size();
        // recursive dp:
        // vector<vector<int>>dp(n, vector<int>(m,-1));
        // return f(s,p,n-1,m-1,dp);
        
        // Iterative dp:
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for (int i = 0; i < n+1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < m+1; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i-1][j],
                                       min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};