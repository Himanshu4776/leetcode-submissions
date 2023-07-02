class Solution {
public:
    int ans = 0;
    void solve(int i,vector<int>&nums,int val){
        if( i >= nums.size())
        {
            ans += val;
            return;
        }        
        solve(i+1,nums,val^nums[i]);
        solve(i+1,nums,val);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int val = 0;
        solve(0,nums,val);
        return ans;
    }
};