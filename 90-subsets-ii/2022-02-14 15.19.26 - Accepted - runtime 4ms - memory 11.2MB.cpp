class Solution {
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds, bool prev)
    {
        if(i >= nums.size())
        {
            ans.push_back(ds);
            return;
        }
        solve(i+1,nums,ans,ds, false);
        if(i>0 && nums[i] == nums[i-1] && !prev) return;
        
        ds.push_back(nums[i]);
        solve(i+1,nums,ans,ds, true);
        ds.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        // one solution is using the hashmap for ds but here we will do one more thing.
        vector<int>ds;
        int i;
        bool prev = false;
        solve(0,nums,ans,ds,prev);
        return ans;
    }
};