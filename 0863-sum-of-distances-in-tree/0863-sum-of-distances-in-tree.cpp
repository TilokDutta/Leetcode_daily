class Solution {
public:
    vector<int> count;
    long root_result = 0;
    int N;
    void resDfs(vector<vector<int>>& adj, int node,int parent,vector<int>& result){
        for (auto it : adj[node]){
            if (it != parent){
                result[it] = result[node] - count[it] + (N - count[it]);
                resDfs(adj,it,node,result);
            }
        }
    }
    int dfs(vector<vector<int>>& adj, int node, int parent, int dist){
        root_result += dist;
        int res = 1;
        for(auto it : adj[node]){
            if(it != parent){
                res += dfs(adj,it,node,dist+1);
            }
        }
        count[node] = res;
        return res;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.resize(n,0);
        N = n;
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(adj,0,-1,0);
        vector<int> result(n,0);
        result[0] = root_result;
        resDfs(adj,0,-1,result);
        return result;
    }
};