class Solution {
public:
    bool dfs(int i, int j,int mid, int m, int n, vector<vector<int>>& h, int v[100][100])
    {
        if(i == n-1 && j == m-1) return true;
        v[i][j] = 1;
        bool op = false;
    
        if(i>0 && v[i-1][j]==0 && abs(h[i][j] - h[i-1][j]) <= mid)
            op = op||dfs(i-1,j,mid,m,n,h,v);
        if(j>0 && v[i][j-1]==0 && abs(h[i][j] - h[i][j-1]) <= mid)
            op = op||dfs(i,j-1,mid,m,n,h,v);
        if(i<n-1 && v[i+1][j]==0 && abs(h[i][j] - h[i+1][j]) <= mid)
            op = op||dfs(i+1,j,mid,m,n,h,v);
        if(j<m-1 && v[i][j+1]==0 && abs(h[i][j] - h[i][j+1]) <= mid)
            op = op||dfs(i,j+1,mid,m,n,h,v);
        
        return op;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        long long int n = heights.size(),m = heights[0].size();
        long long int s = 0, e = INT_MAX;
        long long int ans = INT_MAX;
        while(e >= s)
        {
            long long int mid = s+(e-s)/2;
            int v[100][100];// visited array
            memset(v,0,sizeof(v));
            if(dfs(0,0,mid,m,n,heights,v) == true) {
                ans = min(ans, mid);
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return ans;
    }
};