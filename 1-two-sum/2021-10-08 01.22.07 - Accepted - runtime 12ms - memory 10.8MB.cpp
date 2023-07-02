class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // this was a brute force approach:
        // for(int i=0; i<=nums.size();i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             return vector<int> {i,j};
        //         }
        //     }
        // }
        // return {};
        
        // lets optimize it:
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            if(m.count(target - nums[i]))
                return {m[target - nums[i]],i};
            
            m[nums[i]] = i;
        }
        return {};
    }
};