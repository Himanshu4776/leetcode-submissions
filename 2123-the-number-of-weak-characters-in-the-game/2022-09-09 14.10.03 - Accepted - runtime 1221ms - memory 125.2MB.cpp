class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b) {
        if(a[0] == b[0]) return a[1] > b[1];
        
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int ans = 0,val = INT_MIN;
        
        for(int i = properties.size()-1; i>=0; i--)
        {
            if(properties[i][1] < val) {
                ans++;
            }
            val = max(val, properties[i][1]);
        }
        
        return ans;
    }
};