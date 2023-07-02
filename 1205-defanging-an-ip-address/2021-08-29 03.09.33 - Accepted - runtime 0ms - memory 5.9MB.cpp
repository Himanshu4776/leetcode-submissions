class Solution {
public:
    string defangIPaddr(string a) {
        string ans="";
        for(int i=0; i<a.length();i++)
        {
            if(a[i] == '.')
            {
                ans += "[.]";
            }
            else
            {
                ans += a[i];
            }
        }
        return ans;
    }
};