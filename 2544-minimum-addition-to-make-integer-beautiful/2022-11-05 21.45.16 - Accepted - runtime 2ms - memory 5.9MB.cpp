class Solution {
public:
    long long sum(long long n) {
        long long res = 0;
        while(n > 0) {
            res += n%10;
            n = n/10;
        }
        return res;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long long prevValue = n, base = 1;
        while (sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        // Means only lastdig * pow(10, no of times loop occured) - origionalValue is our solution.
        return n * base - prevValue;
    }
};