class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
//         vector<int> vals; 
//         for (auto& row : grid)
//             for (auto& x : row)
//                 vals.push_back(x); 
        
//         for (auto& v : vals)
//             if ((v - vals[0]) % x) return -1; 
        
//         sort(vals.begin(), vals.end()); 
//         int ans = 0, median = vals[vals.size()/2]; 
//         for (auto& v : vals) ans += abs(v - median)/x; 
//         return ans;
        vector<int>arr;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        
        int t=arr[m*n/2],a=0;
        
        for(int i=0;i<m*n;i++)
        {
            if(abs(arr[i]-t)%x!=0)
                return -1;
            else
                a+=abs(arr[i]-t)/x;
        }
        return a;
    }
};