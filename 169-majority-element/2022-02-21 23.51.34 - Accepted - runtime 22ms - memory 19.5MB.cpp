class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)// means no. is starting so start the count.
            {
                count++;
                ans = nums[i];
            }
            else if(nums[i] == ans)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return ans;
    }
};