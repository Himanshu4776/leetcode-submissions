class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        int minEle = INT_MAX, profit = 0;
        for(int i=0;i<n;i++) {
            if(minEle > prices[i]) {
                minEle = prices[i];
            }
            maxProfit = max(maxProfit, prices[i] - minEle);
        }
        return maxProfit;
    }
};