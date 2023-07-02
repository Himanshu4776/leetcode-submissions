class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2, j = i + 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        // edge case: already the highest permutation you can get
        // if the array is sorted in reverse order the return the reversed array.
        if (i == -1) {
            reverse(begin(nums), end(nums));
            return;
        }
        // finding the first element > nums[i]
        while (nums[--j] <= nums[i]);
        // swapping i and j's values(as they are the ones need to change)
        swap(nums[i], nums[j]);
        // reverse the array after index to end of array
        sort(begin(nums) + i + 1, end(nums));
    }
};