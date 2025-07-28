class Solution {
public:
    void dfs(vector<bool> &vis, int &index, vector<vector<int>>& stones){
        vis[index] = 1;
        for(int j = 0; j < stones.size(); j++){
            int r = stones[j][0];
            int c = stones[j][1];
            if((r == stones[index][0] || c == stones[index][1]) && vis[j] == 0){
                dfs(vis,j,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n,0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(vis,i,stones);
                count++;
            }
        }
        return n-count;
    }
};