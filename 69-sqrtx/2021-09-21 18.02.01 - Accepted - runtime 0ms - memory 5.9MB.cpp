class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        if(x<0)
            return 0;
        int l = 0,r = x,res;
        while(l<=r)
        {
            long long int mid = (r+l)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid > x)
                r = mid-1;
            else
            {
                l = mid+1;
                res = mid;
            }
        }
        return res;
    }
};