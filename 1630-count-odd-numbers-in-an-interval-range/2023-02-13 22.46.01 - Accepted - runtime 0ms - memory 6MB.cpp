class Solution {
public:
    int countOdds(int low, int high) {
        long long int ans = 0;
        // O(n) solution
        // for(int i=low;i<=high;i++) {
        //     if(i%2 != 0) {
        //         ans++;
        //     }
        // }
        // return ans;

        if((low%2!=0 && high%2!=0) || (low%2!=0 && high%2==0) || (low%2==0 && high%2!=0) )
        {
            return ((high-low)/2)+1;
        }
        else return (high-low)/2;
    }
};