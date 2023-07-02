class Solution {
public:
    void solve(int i,vector<vector<int>>&ans,vector<int>& nums) {
        if( i == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int d = i;d<=nums.size()-1;d++)
        {
            // Lets check if we are not swapping the same element values.
            // as they won't give us new permutation to us.
            if(nums[i] == nums[d] && i!=d) continue;
            // if i used a number once then next time i would
            //  want to not to use that one.
            // so i will store it in a set.
            if(s.find(nums[d]) != s.end()) continue;
            s.insert(nums[d]);
            // we have to insert it to check if we have used previously or not
            
            swap(nums[d],nums[i]);
            solve(i+1,ans,nums);
            swap(nums[d],nums[i]);
            // solve(i+1,ans,nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,ans,nums);
        return ans;
    }
};