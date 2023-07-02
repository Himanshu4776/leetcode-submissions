class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size(),least = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<n-1;i++)
        {
            least = min(least,arr[i+1]-arr[i]);
        }
        vector<vector<int>>ans;
        for(int i =0;i<n-1;i++)
        {
            vector<int>vals;
            int minval = arr[i+1]-arr[i];
            if(minval == least)
            {
                vals.push_back(arr[i]);
                vals.push_back(arr[i+1]);
                ans.push_back(vals);
            }
        }
        return ans;
    }
};