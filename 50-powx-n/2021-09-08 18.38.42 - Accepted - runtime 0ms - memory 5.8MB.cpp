class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || n == 1)
            return n== 0 ? 1 : x;
        if(n==-1)
            return 1/x;
        
        double res = myPow(x,n/2);
        
        if(n%2 == 0)
            return res*res;
        else
            return res * res * (n < 0 ? (1 / x) : x);
    }
};