class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj, int node, int parent, vector<int> &count,string &labels){
        vector<int> storenode(26,0);
        storenode[labels[node] - 'a']++;
        for(auto it : adj[node]){
            if(it != parent){
                vector<int> childFreq = dfs(adj,it,node,count,labels);
                for(int i = 0; i < 26; i++){
                    storenode[i] += childFreq[i];
                }
            }
        }
        count[node] = storenode[labels[node] - 'a'];
        return storenode;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> count(n,0);
        dfs(adj,0,-1,count,labels);
        return count;
    }
};