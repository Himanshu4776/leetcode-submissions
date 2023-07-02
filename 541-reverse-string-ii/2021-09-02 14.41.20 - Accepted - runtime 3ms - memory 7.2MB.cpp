class Solution {
public:
    string reverseStr(string s, int k) {
        if(k>= s.size())
        {
            reverse(s.begin(),s.end());
            return s;
        }
        for(int j=0;j<s.size();j+=2*k)
        {
            if(j+k < s.size())
                reverse(s.begin()+j,s.begin()+j+k);
            else
                reverse(s.begin()+j,s.end());
        }
        return s;
    }
};