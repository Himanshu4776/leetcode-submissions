class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string res = "";
        int n = str.size();
        if(n==0)
            return "";
        if(n==1)
            return str[0];
        sort(str.begin(),str.end());
        // max diifernce after sorting will be of first and the last value
        for(int i=0;i<str[0].size();i++)
        {
            if(str[0][i] == str[n-1][i])
                res += str[0][i];
            else
                break;
        }
        return res;
    }
};