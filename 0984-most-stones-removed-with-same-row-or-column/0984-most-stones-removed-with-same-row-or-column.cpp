class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        } 
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulP_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulP_u == ulp_v) return;
        if(rank[ulP_u] < rank[ulp_v]){
            parent[ulP_u] = ulp_v;
        }else if(rank[ulP_u] > rank[ulp_v]){
            parent[ulp_v] = ulP_u;
        }else{
            parent[ulp_v] = ulP_u;
            rank[ulP_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulP_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulP_u == ulp_v) return;
        if(size[ulP_u] < size[ulp_v]){
            parent[ulP_u] = ulp_v;
            size[ulp_v] += size[ulP_u];
        }else{
            parent[ulp_v] = ulP_u;
            size[ulP_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> edges;

        int n = stones.size();
        for(int i = 0; i < n; i++){
            int x = stones[i][0];
            int y = stones[i][1];
            for(int j = i+1; j < n; j++){
                if(stones[j][0] == x || stones[j][1] == y){
                    edges.push_back({i,j});
                }
            }
        }

        DisjointSet ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u) != ds.findUParent(v)){
                ds.unionBySize(u,v);
            }
        }
        int unConnected = 0;
        for(int i = 0 ;i < n; i++){
            if(ds.findUParent(i) == i){
                unConnected++;
            }
        }
        return n == 1 ? 0 : n-unConnected;
    }
};