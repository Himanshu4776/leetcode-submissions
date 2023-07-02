class Solution {
    void solve(int i,vector<vector<int>>&ans,vector<int>&nums, vector<int>&ds)
    {
        if(i >= nums.size())
        {
            ans.push_back(ds);
            return;
        }
        solve(i+1,ans,nums,ds);
        ds.push_back(nums[i]);
        solve(i+1,ans,nums,ds);
        ds.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i;
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,ans,nums,ds);
        return ans;
    }
};