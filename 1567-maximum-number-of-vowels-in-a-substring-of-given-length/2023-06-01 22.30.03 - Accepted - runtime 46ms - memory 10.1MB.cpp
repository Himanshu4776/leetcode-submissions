class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int>m;
        m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = 1;
        
        int curr = 0,maxval = INT_MIN, i, j =0, n = s.size();
        for(i=0;i<k;i++) {
            if(m[s[i]] > 0) curr++;
        }
        maxval = max(maxval,curr);
        // j is initial point of window and i is final point of window
        // i++;
        
        for(i;i<n;i++) {
            if(m[s[i]] > 0) curr++;
            if(m[s[j]] > 0) curr--;

            maxval = max(maxval,curr);
            j++;
        }
        return maxval;
    }
};