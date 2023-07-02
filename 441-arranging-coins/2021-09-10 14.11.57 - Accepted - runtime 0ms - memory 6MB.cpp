class Solution {
public:
    int arrangeCoins(int n) {
        // int i= 1;
        // int res = 0;
        // while(n>=i)
        // {
        //     n = n- i;
        //     res++;
        //     i++;
        // }
        // return res;
        
        // lets try out another approach (more efficient):
        return floor(-0.5+sqrt((double)2*n+0.25));
    }
};