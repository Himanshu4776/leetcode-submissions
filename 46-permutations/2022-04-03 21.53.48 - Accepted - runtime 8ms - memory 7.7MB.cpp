class Solution {
public:
    void solve(int i,vector<vector<int>>&ans,vector<int>& nums)
    {
        if( i == nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int d = i;d<=nums.size()-1;d++)
        {
            swap(nums[d],nums[i]);
            solve(i+1,ans,nums);
            swap(nums[d],nums[i]);
            // solve(i+1,ans,nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,ans,nums);
        return ans;
    }
};