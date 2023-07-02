class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maximum_value = INT_MIN;
        vector<int>arr;
        int count = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] != 0) count++;
            else {
                arr.push_back(count);
                arr.push_back(0);
                count = 0;
            }
        }
        // check if count is still left after array completion. then push it
        if(count > 0) arr.push_back(count);
        
        // iterate for the best answer and check for corner case
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == 0) {
                if(i == 0) {
                    maximum_value = max(maximum_value, arr[1]);
                } else if(i == arr.size()-1) {
                    maximum_value = max(maximum_value, arr[arr.size()-2]);
                } else {
                    maximum_value = max(maximum_value, arr[i-1] + arr[i+1]);
                }
            }
        }

        if(maximum_value == INT_MIN) return (arr[0]-1);

        return maximum_value;
    }

    // Best solution without extra space:

    // int longestSubarray(vector<int>& nums)
    // {         
    //     const int n = nums.size();

    //     int l = 0;      // left index of a sliding window
    //     int r = 0;      // right index of a sliding window (not inclusive)
    //     int flips = 1;  // number of remaining available flips
    //     int maxLen = 0;

    //     while (r < n)
    //     {
    //         if (nums[r] == 0)
    //             flips--;

    //         if (flips < 0)
    //         {
    //             while (nums[l++]) {}
    //             flips++;
    //         }

    //         maxLen = max(maxLen, r - l);
    //         r++;
    //     }

    //     return maxLen;
    // }
};