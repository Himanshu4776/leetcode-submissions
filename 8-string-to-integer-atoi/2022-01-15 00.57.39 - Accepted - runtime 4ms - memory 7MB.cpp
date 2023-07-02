class Solution {
public:
    int myAtoi(string input) {
//         int n = input.size();
//         bool flag = 0;
//         int sign = 1;
//         string s = "";
        
//         for(int i=0;i<n;i++)
//         {
//             if(input[i] == '+' || input[i] == ' ')
//                 continue;
//             else if(input[i] == '0' && flag == false)
//                 continue;
//             else if(input[i] == '-')
//                 sign = -1;
//             else
//             {
//                 flag = true;
//                 s += input[i];
//             }
//         }
//         int res = 0,size = s.size();
//         for(int i=0;i<size;i++)
//         {
//             int dig = s[i] - '0';
//             if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && dig > INT_MAX % 10)) { 
//                 return sign == 1 ? INT_MAX : INT_MIN;
//             }
            
//             if(dig >= 0 && dig < 10)
//                 res = res*10+ dig;
//             else
//                 return res*sign;
//         }
        
//         return res*sign;
        int sign = 1; 
        int result = 0; 
        int index = 0;
        int n = input.size();
        
        while (index < n && input[index] == ' ') { 
            index++; 
        }
         
        if (index < n && input[index] == '+') {
            sign = 1;
            index++;
        } else if (index < n && input[index] == '-') {
            sign = -1;
            index++;
        }
        
        while (index < n && isdigit(input[index])) {
            int digit = input[index] - '0';

            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                return sign == 1 ? INT_MAX : INT_MIN;
            }            
            result = 10 * result + digit;
            index++;
        }
        
        return sign * result;
    }
};