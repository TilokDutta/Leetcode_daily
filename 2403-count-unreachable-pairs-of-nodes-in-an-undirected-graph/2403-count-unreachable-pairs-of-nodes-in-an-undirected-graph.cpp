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
        int parX = find(x);
        int parY = find(y);
        if(parX == parY){
            return;
        }
        if(rank[parX] > rank[parY]){
            parent[parY] = parX;
        }else if(rank[parY] > rank[parX]){
            parent[parX] = parY;
        }else{
            parent[parY] = parX;
            rank[parX]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(auto it : edges){
            if(find(it[0]) != find(it[1])){
                unionSet(it[0],it[1]);
            }
        }
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[find(i)]++;
        }
        vector<int> s;
        for(auto it : mp){
            s.push_back(it.second);
        }
        long long count = 0, sum = 0;
        for(int i = 0; i < s.size(); i++){
            count += (long long)s[i] * sum;
            sum += s[i];
        }

        return count;
    }
};
