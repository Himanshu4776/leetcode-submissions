class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        string s = columnTitle;
        int len = s.length();
        for(int i=0; i<len;i++)
        {
            ans = ans*26 + (s[i] -'A' + 1);
        }
        return ans;
    }
};