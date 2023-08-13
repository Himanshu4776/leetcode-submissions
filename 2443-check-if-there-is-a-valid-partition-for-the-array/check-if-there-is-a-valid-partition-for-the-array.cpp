class Solution {
public:
    bool solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(i == n) return true;
        
        if(dp[i] != -1) return dp[i];

        if(i+1<n && nums[i] == nums[i+1]) {
            if(solve(i+2, n, nums, dp)) return dp[i] = true;
        }

        if(i+2 < n && (nums[i] == nums[i+1] && nums[i+1] == nums[i+2])) {
            if(solve(i+3, n, nums, dp)) return dp[i] = true;
        }

        if(i+2<n && (nums[i]+1 == nums[i+1]) && nums[i+1] +1 == nums[i+2]) {
            if(solve(i+3, n, nums, dp)) return dp[i] = true;
        }

        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(0, n, nums, dp);
    }
};