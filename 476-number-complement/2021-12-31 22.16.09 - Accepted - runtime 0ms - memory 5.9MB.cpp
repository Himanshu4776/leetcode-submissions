class Solution {
public:
    int findComplement(int num) {
        return (pow(2,floor(log2(num))+1)-1)-num;
        
// Here, floor(log2(num))+1 gives us the number of bits in integer num.
// The maximum value obtained with this number of bits is pow(2,no of bits)-1.

        
        // one more approach could be xor operation to max no of 1's to num.
    }
};