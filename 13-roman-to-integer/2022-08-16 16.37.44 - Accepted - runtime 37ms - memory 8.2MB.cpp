class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int n = s.size();
        for(int j=0;j<n-1;j++) 
        {
            // when 4,9 comes then as IV so here next element is greater then curr
            // this indication is follwed in 4 as well as 9.
            if(m[s[j+1]] > m[s[j]]) {
                ans -= m[s[j]];
            }
            else {
                ans += m[s[j]];
            }
        }
        ans += m[s[n-1]];
        
        return ans;
    }
};