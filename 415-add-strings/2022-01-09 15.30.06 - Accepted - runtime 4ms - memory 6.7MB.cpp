class Solution {
public:
    string addStrings(string nums1, string nums2) {
        string res = "";
        int n = nums1.size(),m = nums2.size(),carry = 0;
        while(n || m)
        {
            if(n && m){
                int temp = nums1[n-1] - '0' + nums2[m-1] - '0' + carry;
                res += temp%10 + '0';
                carry = temp/10;
                n--;m--;
            }
            else if(n && !m){
                int temp = nums1[n-1] - '0' + carry;
                res += temp%10 + '0';
                carry = temp/10;
                n--;
            }
            else if(!n && m){
                int temp = nums2[m-1] - '0' + carry;
                res += temp%10 + '0';
                carry = temp/10;
                m--;
            }
            else{
                res += carry + '0';
            }
        }
        if(carry){res += carry + '0';}
        reverse(res.begin(),res.end());
        return res;
    }
};