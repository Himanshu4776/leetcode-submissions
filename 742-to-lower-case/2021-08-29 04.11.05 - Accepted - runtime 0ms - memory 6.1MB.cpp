class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(islower(s[i]))
            {
                ans += s[i];
            }
            else if(s[i] > 64 && s[i] < 91)
            {
                ans += s[i] + 32;
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};