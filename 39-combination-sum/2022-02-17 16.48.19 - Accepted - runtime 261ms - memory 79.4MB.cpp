class Solution {
public:
    void backtrack(int i,vector<int>&candidates,int sum,int target,vector<int>track,vector<vector<int>>&ans)
    {
        if(sum == target)
        {
            ans.push_back(track);
            return;
        }
        if(sum > target || i >= candidates.size())
            return;
        
        track.push_back(candidates[i]);
        backtrack(i,candidates,sum+candidates[i],target,track,ans);
        track.pop_back();
        backtrack(i+1,candidates,sum,target,track,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>track;
        backtrack(0,candidates,0,target,track,ans);
        return ans;
    }
};