class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = find(parent[n]);
    }
    void unionSet(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }

        auto lambda = [&](vector<int> &v1, vector<int> &v2){
            return v1[2] < v2[2];
        };

        sort(edgeList.begin(),edgeList.end(),lambda);
        sort(queries.begin(),queries.end(),lambda);

        int j = 0;

        vector<bool> result(queries.size());

        for(int i = 0; i < queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int t = queries[i][2];
            int idx = queries[i][3];
            while( j < edgeList.size() && edgeList[j][2] < t){
                unionSet(edgeList[j][0] , edgeList[j][1]);
                 j++;
            }

            if(find(u) == find(v)){
                result[idx] = true;
            }else{
                result[idx] = false;
            }
        }
        return result;
    }
};