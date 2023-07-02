class Solution {
public:
    // bool isPalindrome(string s) {
    //     string dup = s;
    //     int n = s.length()-1;
    //     int i=0;
    //     while(i<n)
    //     {
    //         if(!isalnum(s[i]))
    //             i++;
    //         else if(!isalnum(s[n]))
    //             n--;
    //         else if(tolower(s[i]) != tolower(s[n]))
    //             return false;
    //         else
    //         {
    //             i++;
    //             n--;
    //         }
    //     }
    //     return true;
    // }
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(!isalnum(s[l]))
                l++;
            else if(!isalnum(s[r]))
                r--;
            else if(tolower(s[l])!=tolower(s[r]))
                return false;
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};