class Solution {
public:
    static bool comp(pair<char,int>&elem1, pair<char,int>&elem2) {
        return elem1.second > elem2.second;
    };
    
    string frequencySort(string s) {
        unordered_map<char, int>m;
        int n = s.size();
        for(int i=0;i<n;i++) {
            m[s[i]]++;
        }
        
        vector<pair<char,int>>v;
        for(auto it: m) {
            v.push_back(make_pair(it.first,it.second));
        }
        
        sort(v.begin(), v.end(), comp);
        
        string res = "";
        for(auto it: v) {
            while(it.second > 0) {
                res += it.first;
                it.second--;
            }
        }
        return res;
    }
};