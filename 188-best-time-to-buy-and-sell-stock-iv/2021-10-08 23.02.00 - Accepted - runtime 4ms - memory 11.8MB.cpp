class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
 
        int n = prices.size();
        if(prices.size()==0||k==0) return 0;
        
        vector<vector<int>> dp( k+1 , vector<int> (n));
 
 
        for(int i=0;i<=k;i++)
            dp[i][0] = 0;
 
        for(int j=0;j<n;j++)
            dp[0][j] = 0;
        
        
        for(int i=1;i<=k;i++){
            int maxTemp = -prices[0];
            for(int j=1;j<n;j++){
                
                dp[i][j] = max(dp[i][j-1] , prices[j] + maxTemp);
                maxTemp = max(maxTemp, dp[i-1][j-1] - prices[j]);
                
            }
        }
        
        return dp[k][n-1];
        
    }
};