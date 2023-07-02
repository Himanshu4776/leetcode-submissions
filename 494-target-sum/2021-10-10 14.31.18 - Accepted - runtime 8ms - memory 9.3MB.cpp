class Solution {
public:
    int countsubsetsum(vector<int>&arr,int sum,int n)
    {
        int t[n+1][sum+1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i==0)
                    t[i][j] = 0;
                if (j==0)
                    t[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i-1] <= j)
                    t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum = 0;
//         if(n==1&&nums[0]!=target)
//             return 0;
        
//         for(int i=0;i<n;i++)
//             sum += nums[i];
        
//         int val = (target+sum)/2;
        
//         if(sum < target || ((sum + target) % 2)!=0 || val<0)
//             return 0;
        
//         return countsubsetsum(nums,val,n);
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int new_target = (sum + target)/2;
        if(sum < target || (sum + target)%2 != 0 || new_target<0)
            return 0;
        
        vector<int>dp(new_target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = new_target; j >= nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        return dp[new_target];
    }
};