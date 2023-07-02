class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i,n = nums.size();
        vector<int>res;
        for(i=0;i<n;i++) {
            if(nums[i] >= 0) break;
        }
        int j = i-1;
        while(j>=0 && i<n) {
            int sq1 = nums[i]*nums[i];
            int sq2 = nums[j]*nums[j];
            
            if(sq1 > sq2) {
                res.push_back(sq2);
                j--;
            }
            else {
                res.push_back(sq1);
                i++;
            }
        }
        while(i<n)
        {
            res.push_back(nums[i]*nums[i]);
            i++;
        }
        
        while(j>=0)
        {
            res.push_back(nums[j]*nums[j]);
            j--;
        }
        
        return res;
    }
};