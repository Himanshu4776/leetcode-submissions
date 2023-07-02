class Solution {
public:
    vector<int> findAnagrams(string str, string ptr) {
        vector<int> res;
        int s = str.size();
        int p = ptr.size();
        if(s < p) return res;
        
        vector<int>pf(26,0);
        vector<int>win(26,0);
        for(int i=0;i<p;i++)
        {
            pf[ptr[i] - 'a']++;
            win[str[i] - 'a']++;
        }
        if(pf == win) res.push_back(0);
        // means the ptr string is same as str
        
        for(int i=p;i<s;i++)
        {
            win[str[i-p] - 'a']--;
            win[str[i] - 'a']++;
            // new elemnt added and prev one removed now let's check
            if(pf == win) res.push_back(i-p+1);
        }
        return res;
    }
};