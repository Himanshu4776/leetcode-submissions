class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        // now lets check which first value is unique;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};