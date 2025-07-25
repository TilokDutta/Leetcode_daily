class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edgeCount = connections.size();
        if(edgeCount < n-1) return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int count = n;
        for(int i = 0; i < edgeCount; i++){
            int parent_x = find(connections[i][0]);
            int parent_y = find(connections[i][1]);
            if(parent_x != parent_y){
                unionSet(connections[i][0],connections[i][1]);
                count--;
            }
        }
        return count-1;
    }
};