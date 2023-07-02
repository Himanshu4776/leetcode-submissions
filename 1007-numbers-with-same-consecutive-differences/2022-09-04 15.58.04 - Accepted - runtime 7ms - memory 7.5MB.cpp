class Solution {
public:
    void f(int n, int num, int k, int lastdig, vector<int>&ans) {
        if(n == 0 ) {
            ans.push_back(num);
            return;
        }
        
        for(int i=0;i<=9; i++) {
            if(abs(i-lastdig) == k) {
                f(n-1, num*10 + i, k, i, ans);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        // numbers hould not be starting with 0 that's why we will start the loop from 1.
        for(int i=1;i<=9;i++) {
            f(n-1, i, k, i, ans);
        }
        return ans;
    }
};