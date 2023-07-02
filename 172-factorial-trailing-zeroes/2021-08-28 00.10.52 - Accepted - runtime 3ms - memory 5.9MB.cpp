class Solution {
public:
    int trailingZeroes(int n) {
        int num = n;
        int count = 0;
        while(num!=0)
        {
            int temp = num/5;
            count += temp;
            num = temp;
        }
        return count;
        
    }
};