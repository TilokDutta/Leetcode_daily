class Solution {
public:
int maxi;
    int dfs(vector<vector<int>> &adj,int node,int parent, string& s){
        int longest = 0;
        int sLongest = 0;
        for(auto it : adj[node]){
            if(it != parent){
                int child_longest = dfs(adj,it,node,s);
                if(s[it] == s[node]) continue;
                if(child_longest > sLongest){
                    sLongest = child_longest;
                }
                if(sLongest > longest){
                    swap(sLongest,longest);
                }
            }
        }
        int koi_ek_achha = max(longest,sLongest) +1;
        int only_root_achha = 1;
        int neche_ans_milgya = longest + sLongest +1;
        maxi = max({maxi,koi_ek_achha,only_root_achha,neche_ans_milgya});
        return max(only_root_achha,koi_ek_achha);
    }
    int longestPath(vector<int>& parent, string s) {
        maxi = INT_MIN;
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(adj,0,-1,s);
        return maxi;
    }
};