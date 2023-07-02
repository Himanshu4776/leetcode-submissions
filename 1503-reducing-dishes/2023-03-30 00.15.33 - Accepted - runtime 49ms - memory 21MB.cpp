class Solution {
public:
    int solve(int i, int time, vector<int>& sat, vector<vector<int>>&dp) {
        if(i == sat.size()) return 0;

        if(dp[i][time] != -1) return dp[i][time];

        int pick = sat[i]*time + solve(i+1, time+1, sat, dp);
        int notPick = solve(i+1, time, sat, dp);

        return dp[i][time] = max(pick, notPick);
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        // Memoization approach:
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return solve(0,1,sat,dp);

        // Tabulation
        vector<vector<int>>dp(n+1, vector<int>(n+2,0));
        int total = 0;
        for(int i=n-1;i>=0;i--) {
            for(int time = 1; time <= n; time++) {
                int pick = sat[i]*time + dp[i+1][time+1];
                int notPick = dp[i+1][time];

                dp[i][time] += max(pick, notPick);
            }
        }
        return dp[0][1];
    }
};