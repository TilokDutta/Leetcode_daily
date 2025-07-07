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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u) != ds.findUParent(v)){
                ds.unionBySize(u,v);
            }else{
                extraEdges++;
            }
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(ds.findUParent(i) == i){
                components++;
            }
        }
        if(extraEdges >= components-1){
            return components-1;
        }
        return -1;
    }
};