class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int zeros = 0,score = 0,ones = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] != 0) ones++;
        }
        for(int i=0;i<=n;i++)
        {
            if((ones + zeros) > score){
                score = ones+zeros;
                ans.clear();
            }
            if((ones + zeros) == score) ans.push_back(i);
            if(i<nums.size()){
                if(nums[i] == 0) zeros++;
                ones -= nums[i];
            }
        }
        return ans;
    }
};