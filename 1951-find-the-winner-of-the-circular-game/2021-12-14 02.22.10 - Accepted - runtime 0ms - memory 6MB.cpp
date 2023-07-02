class Solution {
public:
    int f(int n, int k)
    {
        if(n == 1) return 0;
        
        return (f(n-1,k) + k)%n;
    }
    int findTheWinner(int n, int k) {
        if(n==1) return n;
        
        return (f(n-1,k)+k)%n+1;
    }
};