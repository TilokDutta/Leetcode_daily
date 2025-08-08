class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i = 1; i <= n; i++){
                parent[i] = i;
            }
            components = n;
        }
        int find(int n){
            if(parent[n] == n) return n;
            return parent[n] = find(parent[n]);
        }

        void Union(int x, int y){
            int ParentX = find(x);
            int ParentY = find(y);
            if(ParentX == ParentY) return;
            if(rank[ParentX] > rank[ParentY]){
                parent[ParentY] = ParentX;
            }else if(rank[ParentX] < rank[ParentY]){
                parent[ParentX] = ParentY;
            }else{
                parent[ParentY] = ParentX;
                rank[ParentX]++;
            }
            components--;
        }
        bool isSingleCompo(){
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
        auto lambda = [&](vector<int> &v1, vector<int> &v2){
            return v1[0] > v2[0];
        };

        sort(edges.begin(),edges.end(), lambda);
        int edgeCount = 0;
        for(auto &edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3){
                bool isAdded = false;
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    isAdded = true;
                }
                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    isAdded = true;
                }
                if(isAdded){
                    edgeCount++;
                }
            }else if(type == 2){
                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }
            }else{
                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;
                }
            }
        }
        if(Alice.isSingleCompo() == true && Bob.isSingleCompo() == true){
            return edges.size() - edgeCount;
        }
        return -1;
    }
};