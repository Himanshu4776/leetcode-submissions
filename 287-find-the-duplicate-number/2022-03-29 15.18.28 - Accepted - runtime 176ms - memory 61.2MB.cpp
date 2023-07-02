class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0]; 
        // We will check if they will meet or not. means there is a duplicate or not
        do {
            slow = nums[slow]; 
            fast = nums[nums[fast]]; // just a random value for fast
        } while(slow != fast); 
        
        
        // Now lets find the positon and no we want(duplicate)n .
        fast = nums[0]; 
        while(slow != fast) {
            slow = nums[slow]; 
            fast = nums[fast]; 
        }
        return slow;
    }
};