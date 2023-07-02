class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            // if(m.count(nums[i])!=0 && (abs(i-m[nums[i]])<=k))
            //     return true;
            // else
            //     m[nums[i]] = i;
            if((m.find(nums[i])!=m.end()) && (abs(i-m[nums[i]])<=k))
                return true;
            else
                m[nums[i]] = i;
        }
        return false;
    }
};