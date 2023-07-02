class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size(),target = original;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        while(true)
        {
            if(m[target] > 0)
                target = target*2;
            else
                break;
        }
        return target;
    }
};