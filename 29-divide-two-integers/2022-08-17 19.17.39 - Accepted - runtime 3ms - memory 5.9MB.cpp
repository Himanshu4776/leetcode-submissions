class Solution {
public:
    int divide(int dividend, int divisor) {
        // if limit is being broken by INT_MIN/-1 then return INT_MAX
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool ch1 = 0,ch2 = 0;
        if(dividend < 0) ch1 = 1;
        if(divisor < 0) ch2 = 1;
        divisor = abs(divisor);
        dividend = abs(dividend);
        int res = dividend/divisor;
        if(ch1 == 0 && ch2 == 0 || ch1 == 1 && ch2 == 1) return floor(res);
        
        return floor(res)*-1;
    }
};