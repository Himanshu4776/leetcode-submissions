class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int n = nums.size();
        
        int a = 0, b = 0, curr = 0, i = 0;
        
        int ans = 0;
        while (i < n) {
            if (i != 0 && nums[i-1] != nums[i] - 1) {
                ans += b;
                a = 0;
                b = 0;
            }
            
            int x = nums[i];
            
            while (i < n && nums[i] == x) {
                curr += nums[i];
                i++;
            }
            
            int dummy = max(a + curr, b);
            a = b;
            b = dummy;
            curr = 0;
        }
        
        return ans + b;
    }
};