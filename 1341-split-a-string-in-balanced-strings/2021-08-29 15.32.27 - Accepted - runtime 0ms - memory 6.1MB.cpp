class Solution {
public:
    int balancedStringSplit(string s) {
        int bal = 0;
        int n = s.length();
        vector<int>v;
        if(n == 1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')
            {
                bal++;
            }
            else
            {
                bal--;
            }
            if(bal == 0)
            {
                v.push_back(i);
            }
        }
        // now we got how many times s becomes balanced so lets print it.
        return v.size();
    }
};