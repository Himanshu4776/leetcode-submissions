class Solution {
public:
    void dfs(int node, vector<int>&node_distance, vector<bool>&vis, vector<int>& edges, vector<bool>&currentCycleVis, int distance, int &ans)
    {
        if(node != -1) {
            // means there's no block at this edge
            if(!vis[node]) {
                vis[node] = true;
                currentCycleVis[node] = true;
                node_distance[node] = distance;
                dfs(edges[node], node_distance, vis, edges,currentCycleVis, distance+1, ans);
            }
            else if(currentCycleVis[node] == 1){
                // we found a cycle. so calculate its length
                ans = max(ans, distance - node_distance[node]);
            }
            // Not foun the cycle. Backtrack and remove the value form currentCycleVis
            currentCycleVis[node] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<bool>vis(n,0);
        vector<bool>currentCycleVis(n,0);
        vector<int>node_distance(n,0);
        for(int i=0;i<n;i++) {
            if(vis[i] != 1) {
                dfs(i,node_distance,vis,edges, currentCycleVis, 0, ans);
            }
        }

        return ans;
    }
};