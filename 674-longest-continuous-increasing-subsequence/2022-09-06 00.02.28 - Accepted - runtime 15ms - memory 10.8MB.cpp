class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = INT_MIN;
        int seq = 1;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i-1])
            {
                seq++;
            }
            else
            {
                res = max(res,seq);
                seq = 1;
            }
        }
        
        res = max(res,seq);
        return res;
    }
};