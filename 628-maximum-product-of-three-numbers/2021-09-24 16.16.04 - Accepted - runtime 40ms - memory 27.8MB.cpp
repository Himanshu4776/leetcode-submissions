class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // if array has -ve value then we should check largest(+ve)*lowest(-ve)*low(-ve)
        // is max or largest(n-1)*largest(n-2)*largest(n-3).
        // which is max we should return it.
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    }
};