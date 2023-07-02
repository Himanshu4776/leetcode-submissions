class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n < 3) return ans;
        if(n == 3)
        {
            if((nums[1] - nums[0]) == (nums[2] - nums[1])) return 1;
        }
        int count = 0;
        for(int i=0;i<(n-2);i++)
        {
            if((nums[i+1] - nums[i]) == (nums[i+2] - nums[i+1]))
                count++;
            else
            {
                ans += count*(count+1)/2;
                count = 0;
            }
        }
        if(count != 0)
        {
            ans += count*(count+1)/2;
        }
        return ans;
    }
};






