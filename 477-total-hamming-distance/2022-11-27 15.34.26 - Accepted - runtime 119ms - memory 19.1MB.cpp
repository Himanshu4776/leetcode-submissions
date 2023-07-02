class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0;i<32;i++)
        {
            //count no of zeros and ones for each bit and multiply them
            int one=0;int zero = 0;
            for(int &n : nums)
            {
                if(n&(1<<i)) one++;
                else zero++;
            }
            // using pnc
            res+=(one*zero);
        }
        return res;
    }
};