class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &graph, int node, vector<int> &ans){
        int n = graph.size();
        if(node == n-1){
            res.push_back(ans);
        }
        for(auto it : graph[node]){
            ans.push_back(it);
            dfs(graph,it,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        ans.push_back(0);
        dfs(graph,0,ans);
        return res;
    }
};