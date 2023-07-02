class Solution {
public:
    int getSum(int a, int b) {
        // Approach1: XOR Operator will be used here
        
        unsigned int carry=0;// carry to check when the numbers are ending.
        while(b != 0){
            carry = a & b;
            // For storing the sum we will use XOR operator
            a = a ^ b;
            // We will b get 0 when numbers end and carry will be 0;
            b = carry << 1;
        }
        
        return a;
        
        // Approach 2:
        // return log(exp(a)*exp(b)); this is not suitable for this question as here 
        // n also lies in the negative range/
    }
};