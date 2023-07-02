class Solution {
public:
    int LCS(vector<int>&s, vector<int>&t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m + 1,0));
        int maxlen = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
                maxlen = max(maxlen, dp[i][j]);
            }
        }
        return maxlen;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return LCS(nums1,nums2);
    }
};