class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0,n = nums.size();
        long long leftsum = 0, rightsum = 0;
        
        for(int i=0;i<n;i++) rightsum += nums[i];
        
        for(int i=0;i<n-1;i++) {
            leftsum += nums[i];
            rightsum -= nums[i];
            
            if(leftsum >= rightsum) ans++;
        }
        
        return ans;
    }
};