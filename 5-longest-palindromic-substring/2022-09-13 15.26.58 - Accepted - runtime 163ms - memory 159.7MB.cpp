class Solution {
public:
    int expandFromMiddle(string s, int left, int right) {
        if(left>right) return 0;
        
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(s == "" || n == 0) return "";
        int start = 0;// to store resulting string start index
        int strlen = 0;// to store resulting string length
        
        for(int i=0;i<n;i++) {
            // for odd length palindrome case
            int len1 = expandFromMiddle(s,i,i);
            // for even length palindrome case
            int len2 = expandFromMiddle(s,i,i+1);
            int len = max(len1,len2);
            
            if(strlen < len) {
                start = i - (len/2);
                if(len%2 == 0) start++;
                // len-1 because we are taking the case of i as well.
                strlen = len;
                // len because after start + strlen string end position. 
            }
        }
        return s.substr(start,strlen);
    }
};