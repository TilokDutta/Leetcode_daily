class Solution {
public:
    bool dfs(int node, int color, vector<int> &vis, vector<vector<int>> &graph){
        vis[node] = color;
        for(auto it : graph[node]){
            if(vis[it] == -1){
                if(dfs(it,1-color, vis,graph)){
                    return true;
                }
            }else if( vis[it] == color){
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                if(dfs(i,0,vis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};