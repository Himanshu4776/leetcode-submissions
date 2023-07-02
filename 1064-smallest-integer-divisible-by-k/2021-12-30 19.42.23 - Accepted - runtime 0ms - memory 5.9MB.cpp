class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%10 == 5) return -1;
        if(k == 1) return 1;
        
        int n = 11,count = 2;
        while(true)
        {
            // int temp = n%k;
            n = n%k;
            if(n == 0)
            {
                break;
            }
            else
            {
                count++;// incremented the value of count.
                
                n = n*10;// n value is increased again
                n += 1;
            }
        }
        return count;
    }
};