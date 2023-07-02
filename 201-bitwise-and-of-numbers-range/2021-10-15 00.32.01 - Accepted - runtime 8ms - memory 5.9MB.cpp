class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // int result = left;
        // if(left == 0 || right == 0 )
        // if(left == right)
        //     return left;
        // if(left+1 == right)
        //     return left&right;
        // // if there is a different amount of digits in binary - always will be zero
        // if ((int)log2(left) != (int)log2(right))
        //     return 0;
        // else
        // {
        //     for(int i=left+1;i<=right;i++)
        //     {
        //         result = i&result;
        //     }
        // }
        // return result;
        while(n>m)
           n = n & n-1;
        
        return m&n;
    }
};