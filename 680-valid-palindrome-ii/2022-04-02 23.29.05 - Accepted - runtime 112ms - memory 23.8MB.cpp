class Solution {
public:
    bool ispal(string s,int i,int n)
    {
        while(i<n)
        {
            if(s[i] == s[n])
            {
                i++;n--;
            }
            else
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int count = 0;
        int n = s.length() - 1;
        int i=0;
        while(i<n)
        {
            if(s[i] == s[n])
            {
                i++;
                n--;
            }
            else
            {
                return (ispal(s,i,n-1) || ispal(s,i+1,n));
            }
        }
        return true;
    }
};