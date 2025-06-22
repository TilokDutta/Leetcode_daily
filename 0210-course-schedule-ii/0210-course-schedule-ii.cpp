class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int preReq = prerequisites[i][1];

            adj[preReq].push_back(course);
            inDegree[course]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int pre = q.front();
            q.pop();
            topo.push_back(pre);
            for(auto cour : adj[pre]){
                inDegree[cour]--;
                if(inDegree[cour] == 0){
                    q.push(cour);
                }
            }
        }
        if(topo.size() == numCourses) return topo;
        return {};
    }
};