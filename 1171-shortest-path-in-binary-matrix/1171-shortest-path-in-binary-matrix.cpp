class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<pair<int,int>,int>> q;
        int ans = INT_MAX;
        q.push({{0,0},1});
        vis[0][0] = 1;
        while(!q.empty()){
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            int level = it.second;
            q.pop();
            if(r == n-1 && c == n-1){
                ans  = min(ans,level);
                return ans;
            }

            int drow[] = {-1,-1,-1,1,1,1,0,0};
            int dcol[] = {0,1,-1,0,1,-1,-1,1};
            for(int i = 0; i < 8; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},level+1});
                }
            }
        }
        return -1;
    }
};