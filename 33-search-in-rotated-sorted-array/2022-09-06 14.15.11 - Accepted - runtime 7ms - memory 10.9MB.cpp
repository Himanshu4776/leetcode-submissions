class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0,j=n-1;
        int mid;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] >= nums[i])
            {
                // means left part is sorted so
                // Lets check if target can lie here
                if(nums[mid] >= target && nums[i] <= target) j = mid-1;
                else i = mid+1;
            }
            else
            {
                // Right part is sorted
                if(nums[mid] <= target && nums[j] >= target) i = mid+1;
                else j = mid-1;
            }
        }
        
        return -1;
    }
};