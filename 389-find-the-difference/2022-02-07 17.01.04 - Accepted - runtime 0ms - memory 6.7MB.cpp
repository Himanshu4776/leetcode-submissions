class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        char res = 0;
        for(int i=0;i<n;i++)
        {
            res = res^s[i];
        }
        for(auto d:t)
        {
            res = res^d;
        }
        return res;
    }
};