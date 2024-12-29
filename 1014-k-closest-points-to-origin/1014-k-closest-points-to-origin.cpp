class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        int n = points.size();
        for(int i = 0;i < n; i++){
            double distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({distance,points[i]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};