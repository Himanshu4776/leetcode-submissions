class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sizes = nums.size();
        vector<int> result(sizes,0);
        for(int i=0;i<sizes;i++){
            result[(i + k)%sizes] = nums[i];
        }
        nums = result;
    }
};