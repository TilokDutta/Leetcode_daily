class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> prereq(numCourses);
        vector<int> inDegree(numCourses,0);
        for(int i = 0 ; i < pre.size(); i++){
            prereq[pre[i][1]].push_back(pre[i][0]);
            inDegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int course = q.front();
            ans.push_back(course);
            q.pop();
            for(auto it : prereq[course]){
                inDegree[it] --;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};