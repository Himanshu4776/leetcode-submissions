class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == INT_MAX) continue;
            if(nums[i]%2 == 0)
            {
                ans.push_back(nums[i]);
                nums[i] = INT_MAX;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] == INT_MAX) continue;
            if(nums[i]&1 != 0)
            {
                ans.push_back(nums[i]);
                nums[i] = INT_MAX;
            }
        }
        return ans;
    }
};