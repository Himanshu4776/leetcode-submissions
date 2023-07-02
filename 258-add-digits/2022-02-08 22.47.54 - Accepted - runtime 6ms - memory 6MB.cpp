class Solution {
public:
    int addDigits(int num) {
        // Solution - 1 (Using While loop)
        // while(num>9){
        // 	int rem = num%10;
        // 	num = num/10 + rem;
        //  }
        // return num;

        // Solution - 2 (Using if else ladder)
        // if(num == 0) return 0;
        // else if(num%9 == 0) return 9;
        // else return num%9;

        // Solution - 3 (One Line Code)
        return 1 + (num - 1) % 9;
    }
};