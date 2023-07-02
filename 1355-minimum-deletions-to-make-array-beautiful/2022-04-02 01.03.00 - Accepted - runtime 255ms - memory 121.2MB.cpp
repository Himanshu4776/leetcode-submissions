class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int del = 0, n = nums.size();
        int shift = 0,size = n;
        for(int i=0;i<n-1;i++)
        {
            int shift = i-del;
            if(nums[i] == nums[i+1] && shift%2 == 0)
            {
                del++;
            }
        }
        if((n-del)%2 == 1) del++;// If the remaining length be odd the do one deletion.
        return del;
    }
};