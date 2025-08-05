class Solution {
public:
    int count = 0;
    void dfs(vector<vector<pair<int,int>>> &adj, int node,vector<int> &vis){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                if(it.second == 1){
                    count++;
                }
                dfs(adj,it.first,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> vis(n,0);
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        dfs(adj,0,vis);
        return count;
    }
};