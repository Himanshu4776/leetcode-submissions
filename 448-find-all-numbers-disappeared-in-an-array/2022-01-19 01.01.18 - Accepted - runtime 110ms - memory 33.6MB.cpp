class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int,int>m;
        vector<int>ans;
        
//         for(int i=1;i<=n;i++)
//             m[i] = 0;
        
//         for(auto &i:nums)
//             m[i]++;
        
//         for(auto &i:m)
//             if(i.second == 0) ans.push_back(i.first);

        for(int i=0;i<n;i++) {
            int j = abs(nums[i]);
            if(nums[j-1] > 0)
                nums[j-1] *= -1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};