class Solution {
public:
    void dfs(vector<vector<char>>& grid ,int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return;
        // out of bounds
        
        grid[i][j]='0'; // converted land position to water position
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid,  i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j){
                
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};