class Solution {
public:
    int LCS(string x,string y,int m,int n)
    {
        int t[m+1][n+1];
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i==0 || j==0)
                {
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (x[i-1] == y[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
    }
    // the upper solution was based on LCS.
    
    // lets solve it using memoization:
    int memo[1000][1000] = {};
    int dp(const string& s, int l, int r) {
        if (l > r) return 0; // Return 0 since it's empty string
        if (l == r) return 1; // Return 1 since it has 1 character
        if (memo[l][r] != 0) return memo[l][r];
        if (s[l] == s[r])
            return memo[l][r] = dp(s, l+1, r-1) + 2;
        return memo[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    }
    
    int longestPalindromeSubseq(string s) {
        // Based on LCS:
        // string x = s;
        // reverse(x.begin(),x.end());
        // int m = s.size();
        // int n = x.size();
        // return LCS(s,x,m,n);
        
        // Based on Memoizaton:
        // return dp(s, 0, s.size() - 1);
        
        // Lets apply now bottom-up DP based on this problem:
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};