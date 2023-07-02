class Solution {
    void backtrack(int i,vector<int>&candidates,int target,vector<int>&track,vector<vector<int>>&ans)
    {
        if(target == 0)
        {
            ans.push_back(track);
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(j > i && candidates[j] == candidates[j-1]) continue;
            if(candidates[i] > target) break;
            
            track.push_back(candidates[j]);
            backtrack(j+1,candidates,target-candidates[j],track,ans);
            track.pop_back();
        }
        // backtrack(i+1,candidates,sum,target,track,ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>track;
        sort(candidates.begin(),candidates.end());
        backtrack(0,candidates,target,track,ans);
        return ans;
    }
};