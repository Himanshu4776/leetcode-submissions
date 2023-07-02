class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0, last = 0;
        while (curr < nums.size()) {
            if (nums[curr] != 0) {
                swap(nums[last], nums[curr]);
                last++;
            }
            curr++;
        }
    }
};