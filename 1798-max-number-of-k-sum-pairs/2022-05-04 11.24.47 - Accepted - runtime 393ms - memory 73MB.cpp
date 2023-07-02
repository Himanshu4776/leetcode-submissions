class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        int op = 0;
        for(int i=0;i<n;i++)
        {
            int val = k - nums[i];
            if(m[val] > 0) 
            {
                op++;
                m[val]--;
            }
            else m[nums[i]]++;
        }
        return op;
    }
};