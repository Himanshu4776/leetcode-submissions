class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int N = nums.size();
        while (N!=1) {
            N/=2;
            for (int i = 0; i < N; ++i)
                nums[i] = (i%2 == 0) ? min(nums[2*i], nums[2*i+1]) : max(nums[2*i], nums[2*i+1]);
        }
        return nums[0];
    }
};