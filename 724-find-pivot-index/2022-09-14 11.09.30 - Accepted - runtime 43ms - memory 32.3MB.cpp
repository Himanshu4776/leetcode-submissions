class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>lm(n,0);
        vector<int>rm(n,0);
        
        int sum = 0;
        for(int i=0;i<n;i++) {
            lm[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i=n-1;i>=0;i--) {
            rm[i] = sum;
            sum += nums[i];
        }
        // Now check in lm and rm at same time for first element with pivot value
        for(int i=0;i<n;i++) {
            if(lm[i] == rm[i]) return i;
        }
        return -1;
    }
};