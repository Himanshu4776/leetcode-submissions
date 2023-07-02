class Solution {
public:
    bool isPerfectSquare(long long int num) {
        // long long int end = num;
        // long long int start = 1;
        // while(start <= end)
        // {
        //     long long int mid = (start +end)/2;
        //     if(mid*mid == num)
        //         return true;
        //     else if(mid*mid < num)
        //         start = mid+1;
        //     else
        //         end = mid - 1;
        // }
        // return false;
        
        // another approach:
        long long int i=1;
        if(num==1 || num==0)
            return num;
        while(true)
        {
            if(i*i == num)
                return i;
            else if(i*i > num)
            {
                break;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};