class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]%2 == 0) sum += nums[i];
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int val = queries[i][0], index = queries[i][1];
            // Mantain variables for clean and easy writing code
            if (nums[index] % 2 == 0) sum -= nums[index];
            // removed prev stored value in sum
            nums[index] += val;
            // add new value to the array element
            if (nums[index] % 2 == 0) sum += nums[index];
            // Now add the array index value to sum
            ans.push_back(sum);
        }
        
        return ans;
    }
};