class Solution {
public:
    void dfs(int s, int n, vector<vector<int>>& isConnected, vector<bool>& vis) {
        vis[s] = true;
        vector<int>adj;
        for(int i=0;i<n;i++) {
            if(isConnected[s][i] == 1) {
                adj.push_back(i);
            }
        }

        for(int v: adj) {
            if(!vis[v]) {
                dfs(v, n, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n, false);
        int count = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                count++;
                dfs(i, n, isConnected, vis);
            }
        }
        return count;
    }
};
