class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i = n-1;i>1;i--)
        {
            if(nums[i] < nums[i-1] + nums[i-2])
                return nums[i]+nums[i-1]+nums[i-2];
        }
        return 0;
        // sort(A.begin(), A.end());
        // for (int i = A.size() - 1 ; i > 1; --i)
        //     if (A[i] < A[i - 1] + A[i - 2])
        //         return A[i] + A[i - 1] + A[i - 2];
        // return 0;
    }
};