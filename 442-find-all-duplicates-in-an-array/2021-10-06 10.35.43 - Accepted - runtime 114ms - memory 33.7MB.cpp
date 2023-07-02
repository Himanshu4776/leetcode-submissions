class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        // unordered_map<int,int>m;
        // for(int n:nums)
        // {
        //     m[n]++;
        //     if(m[n] > 1)
        //         ans.push_back(n);
        // }
        
        // lets do it without map in O(n).
        int x=0,y=0;
        for(int num:nums)
        {
            nums[abs(num)-1] *= -1;// made all values -ve.
        }
        // now while traverse if any value is -ve then we push it 
        // and set it bac to -ve.
        for(auto num:nums)
        {
            if(nums[abs(num)-1] > 0)
            {
                ans.push_back(abs(num));
                nums[abs(num)-1] *= -1;
            }
        }
        return ans;
    }
};