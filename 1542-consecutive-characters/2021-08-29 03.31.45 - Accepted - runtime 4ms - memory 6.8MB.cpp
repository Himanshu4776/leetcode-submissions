class Solution {
public:
    int maxPower(string s) {
        int count = 1,maxcount = 0;
        // sort(s.begin(),s.end());
        if(s.length() == 1)
            return 1;
        
        if(s.length() == 0)
            return 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == s[i+1] && i+1<s.length())
            {
                count++;
            }
            else
            {
                maxcount = max(count,maxcount);
                count = 1;
            }
        }
        return maxcount;
    }
};