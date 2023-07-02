class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "",s2 = "";
        int back = 0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] == '#') back++;
            else if(s[i] != '#' && back) {
                back--;
                continue;
            }
            else s1 += s[i];
        }
        back = 0;
        for(int i=t.size()-1;i>=0;i--)
        {
            if(t[i] == '#') back++;
            else if(t[i] != '#' && back) {
                back--;
                continue;
            }
            else s2 += t[i];
        }
        return s1==s2;
    }
};