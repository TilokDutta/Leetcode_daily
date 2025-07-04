class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for(int i = 0 ; i < graph.size(); i++){
            for(int j=0; j < graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i = 0; i < adj.size(); i++){
            inDegree[i] = graph[i].size();
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int course = q.front();
            ans.push_back(course);
            q.pop();
            for(auto it : adj[course]){
                inDegree[it] --;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};