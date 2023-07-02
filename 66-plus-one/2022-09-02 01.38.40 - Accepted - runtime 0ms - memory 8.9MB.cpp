class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        vector<int>ans;
        int n = dig.size();
        for(int i=n-1;i>=0;i--)
        {
            if(dig[i]  < 9) {
                dig[i]++;
                return dig;
            }
            else {
                dig[i] = 0;
            }
        }
        
        vector<int>newarray(n+1,0);
        newarray[0] = 1;
        return newarray;
    }
};