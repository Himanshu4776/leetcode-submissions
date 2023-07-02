class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size(),maxwin = 0;
        // set<char>st;
        // int i=0,j=0;
        // while(j<n)
        // {
        //     if(st.count(s[j]) == 0)
        //     {
        //         st.insert(s[j]);
        //         maxwin = max(maxwin,(int)st.size());
        //         j++;
        //     }
        //     else
        //     {
        //         st.erase(s[i]);
        //         i++;
        //     }
        // }
        // maxwin = max(maxwin,(int)st.size());
        // return maxwin;
        
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];// point where new occurence of char found.
            
            dict[s[i]] = i;// prev oocurence of that char
            maxLen = max(maxLen, i - start);
            // (i-start) === the size of uniques char's window
        }
        return maxLen;
    }
};