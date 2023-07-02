class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1,max_val=INT_MIN;
        //left to right traversal
        for(int i=0;i<nums.size();i++)
        {
            if(prod==0)//if prod becomes 0, prod is reset to 1
                prod=1;
            
            prod=prod*nums[i];
            max_val=max(max_val,prod); 
        }
        //right to left
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(prod==0)
                prod=1;
            
            prod=prod*nums[i];
            max_val=max(max_val,prod);
        }
        return max_val;
    }
};