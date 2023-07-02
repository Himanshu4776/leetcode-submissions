class Solution {
public:
    bool subsetsum(vector<int>&arr, int n, int sum) {
	    bool t[n + 1][sum + 1];
        // dp matrix.
        for (int i = 0; i <= n; i++)
        { 	
            for (int j = 0; j <= sum; j++)
            { 
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; 
                else
                    t[i][j] = t[i - 1][j];
            }
        }
	    return t[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
        }
        if (sum%2 != 0)
            return 0;
        else
            return subsetsum(nums,n,sum/2);
    }
};