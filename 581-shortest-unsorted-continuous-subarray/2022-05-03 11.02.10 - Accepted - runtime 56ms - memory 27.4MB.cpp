class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        // Approach1: Using sorting
        vector<int>arr = nums;
        sort(nums.begin(),nums.end());
        int start = n,end = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != nums[i])
            {
                start = min(start,i);
                end = max(end,i);
            }
        }
        if((end-start) >= 0) return (end-start+1);
        else return 0;
    }
};