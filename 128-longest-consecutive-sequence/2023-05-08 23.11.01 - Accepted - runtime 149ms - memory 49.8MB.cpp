class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Easy approach: by sorting and then traversing.
        unordered_map<int,int>m;
        int ans = 0, count = 0;
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;

        for(int i=0;i<n;i++) m[nums[i]]++;

        for(auto it:m) {
            if(m.find(it.first - 1) == m.end()) {
                int val = it.first;
                count = 1;
                while(m.find(val+1) != m.end()) {
                    val++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};