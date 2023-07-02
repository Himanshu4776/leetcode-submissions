class Solution {
public:
    int longestContinuousSubstring(string s) {
        int temp = 1, maxlen = INT_MIN;
        int n = s.size();
        if(n == 1) return 1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i] + 1 == s[i+1]) {
                temp++;
            }
            else {
                maxlen = max(temp, maxlen);
                temp = 1;
            }
        }
        if(temp > 1) {
            maxlen = max(temp, maxlen);
        }
        
        return maxlen;
    }
};