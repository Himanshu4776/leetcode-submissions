class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        // int count = 0;
        // int res = 0;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i] == 1)
        //         count++;
        //     else
        //     {
        //         res = max(count,res);
        //         count = 0;
        //     }
        // }
        // res = max(count,res);
        // return res;
        
        // alternate and better solution would be:
        int pos = 0,res =0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                res = max(res,i-pos);// count of max consequtive 1.
                pos = i+1;// record of last 0 value
            }
        }
        res = max(res,n-pos);// for ending point we are taking a check of last collection
        return res;
    }
};