class Solution {
public:
    bool checkPowersOfThree(int n) {
//         if(n == 1) return true;
//         else if(n < 3) return false;
        
//         unordered_map<int,int>m;
//         while(n>0)
//         {
//             int i,temp = 1;
//             for(i=1; pow(3,i)<=n;i++)
//             {
//                 temp = pow(3,i);
//             }
//             m[i]++;
//             if(m[i] >= 2) return false;
//             n = n - temp;
//             // cout<<n<<" ";
            
//             if(n == 1 || n == 0) return true;
//             if(n<3) return false;
//         }
//         return true;
        
    // optimized approach without space would be:
        while (n)
        {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};