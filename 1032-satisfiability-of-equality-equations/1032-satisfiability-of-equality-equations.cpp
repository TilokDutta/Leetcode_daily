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
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent.resize(26);
        rank.resize(26,0);
        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            int first = equations[i][0]-'a';
            int second = equations[i][3]-'a';
            if(equations[i][1] == '='){
                unionSet(first,second);
            }
        }
        for(int i = 0; i < n; i++){
            int first = equations[i][0] - 'a';
            int second = equations[i][3] - 'a';
            if(equations[i][1] == '!'){
                int parentF = find(first);
                int parentS = find(second);
                if(parentF == parentS){
                    return false;
                }
            }
        }
        return true;
    }
};