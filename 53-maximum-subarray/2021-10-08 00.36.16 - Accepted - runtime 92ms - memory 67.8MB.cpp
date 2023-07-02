class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum = v[0];
        int maxval = v[0];
        for(int i=1;i<v.size();i++)
        {
            sum = max(v[i],sum+v[i]);
            if(maxval <sum)
            {
                maxval = sum;
            }
        }
        return maxval;
    }
};