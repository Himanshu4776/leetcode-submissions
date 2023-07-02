class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n = nums.size();
        // // we should take two numbers
        // int one = INT_MAX,two = INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     if(one > nums[i])
        //         one = nums[i];
        //     else if(one < nums[i] && two > nums[i])
        //         two = nums[i];
        //     else if(nums[i] > two)
        //         return true;
        // }
        // return false;
        int var1 = INT_MAX;
        int var2 = INT_MAX;
        
        for(int &x: nums){
            if(x <= var1) var1 = x;
            else if(x <= var2) var2 = x;
            else return true;
        }
        return false;
    }
};