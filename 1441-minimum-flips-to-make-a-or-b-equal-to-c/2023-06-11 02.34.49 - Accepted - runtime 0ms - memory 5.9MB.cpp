class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a > 0 || b > 0 || c > 0) {
            int num1 = a&1;
            int num2 = b&1;
            int num3 = c&1;
            if(num3 == 0) {
                count += (num1 + num2);
            } else {
                if(num1 == 0 && num2 == 0) {
                    count += 1;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};