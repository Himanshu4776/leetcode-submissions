class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        int mid;
        while(i<=j)
        {
            mid = (i+j)/2;
            
            if(nums[mid] >= nums[j]) i = mid+1;
            else j = mid;
        }
        return nums[mid];
    }
};