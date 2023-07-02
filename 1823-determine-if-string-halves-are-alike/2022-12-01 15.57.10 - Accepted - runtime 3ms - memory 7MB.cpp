class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char,int>m;
        m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
        m['A'] = m['E'] = m['I'] = m['O'] = m['U'] = 1;
        int i,n = s.size();
        int first = 0, second = 0;
        for(i=0;i<n/2;i++) {
            if(m[s[i]] > 0) first++;
        }
        for(i; i<n;i++) {
            if(m[s[i]] > 0) second++;
        }
        
        return first == second;
    }
};