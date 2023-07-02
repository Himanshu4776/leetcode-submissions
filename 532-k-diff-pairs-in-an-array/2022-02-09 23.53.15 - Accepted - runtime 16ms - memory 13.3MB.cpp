class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size(),ans = 0;
        for(int i=0;i<n;i++) {
            m[nums[i]]++;
        }
        if(k==0) {
            for(auto it:m)
                if(it.second > 1) ans++;
        }
        else {
            for(auto it:m)
            {
                if(m.find(it.first + k) != m.end())
                    ans++;
            }
        }
        
        return ans;
    }
};