class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(s.size() != t.size())
            return false;
        map<char,int>m1;
        for(int i=0; i<n;i++)
        {
            m1[s[i]]++;
        }
        for(char c:t)
        {
            m1[c]--;
            if(m1[c] < 0)
                return false;
        }
        return true;
    }
};