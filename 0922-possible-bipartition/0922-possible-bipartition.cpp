class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> vis(n+1,-1);
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i = 1; i <= n; i++){
            if(vis[i] == -1){
                queue<int> q;
                q.push(i);
                vis[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(vis[it] == -1){
                            vis[it] = 1 - vis[node];
                            q.push(it);
                        }else if(vis[it] == vis[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};