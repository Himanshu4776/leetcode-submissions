class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            res = res^nums[i]^i;
        }
        return res^nums.size();
        // as the only no. left having xor is the size of nums.
        // int sum = 0;
        // for(const int& x: nums)
        //     sum += x;
        // int n = nums.size();
        // return n*(n+1)/2 - sum;
    }
};