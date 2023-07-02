class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int calculate = 0, minimum_value = INT_MAX;
        for(int i=0;i<n;i++) {
            calculate += nums[i];

            if(calculate < 0) {
                minimum_value = min(minimum_value, calculate);
            }
        }
        if(minimum_value >= 0) return 1;

        return abs(minimum_value) + 1;
    }
};
