class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
        vis[node] = 1;
        for(int it : adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    bool isSimilar(string s1, string s2){
        int diff = 0;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                diff++;
            }
        }
        if(diff == 2 || diff == 0) return true;
        return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                count++;
            }
        }
        return count;
    }
};