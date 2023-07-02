class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n, 0);
        int length = nums.size();
        int i,point = 0;
        for(i=0; i<n; i++) {
            ans[point] = nums[i];
            point += 2;
        }
        point = 1;
        for(i; i<2*n; i++) {
            ans[point] = nums[i];
            point+=2;
        }
        return ans;
    }
};