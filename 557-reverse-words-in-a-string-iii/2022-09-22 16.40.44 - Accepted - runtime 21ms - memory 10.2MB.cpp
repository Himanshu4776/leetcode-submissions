class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int space = 0;
        string ans=s;
        for(int i=0;i<n;i++)
        {
            if(s[i] == ' ')
            {
                reverse(ans.begin()+space,ans.begin()+i);
                space = i+1;
            }
        }
        reverse(ans.begin()+space,ans.end());
        return ans;
    }
};