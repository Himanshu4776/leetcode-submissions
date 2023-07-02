class Solution {
public:
    int arraySign(vector<int>& nums) {
        int zero = 0, positive = 0, negative=  0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) zero++;
            else if(nums[i] < 0) negative++;
        }

        if(zero > 0) return 0;
        if(negative%2 == 0) return 1;
        else return -1;
    }
};