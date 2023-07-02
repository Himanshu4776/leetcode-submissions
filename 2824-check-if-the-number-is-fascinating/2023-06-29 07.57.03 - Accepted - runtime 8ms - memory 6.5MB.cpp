class Solution {
public:
    bool isFascinating(int n) {
        string s = "";
        s += to_string(n);
        s += to_string(2*n);
        s += to_string(3*n);
        
        int m = s.size();
        unordered_map<char,int>mp;
        for(int i=1;i<10;i++) {
            mp[i]++;
        }
        for(int i=0;i<m;i++) {
            cout<<s[i]<<" ";
            if(mp[s[i] -'0'] == 0) return false;
            else if(s[i] == '0') return false;
            else mp[s[i]-'0'] = 0;
        }
        
        for(auto it:mp) {
            if(it.second > 0) return false;
        }
        return true;
    }
};