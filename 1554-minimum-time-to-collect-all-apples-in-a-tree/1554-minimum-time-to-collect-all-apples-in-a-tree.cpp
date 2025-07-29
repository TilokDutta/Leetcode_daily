class Solution {
public:
    int dfs(vector<vector<int>> &adj, int node, int parent, vector<bool> &hasApple){
        int time = 0;
        for(auto it : adj[node]){
            if(it != parent){
                int timeChild = dfs(adj,it,node,hasApple);
                if(hasApple[it] || timeChild > 0){
                    time += timeChild + 2;
                }
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj,0,-1,hasApple);
    }
};