class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        int maxTime = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            maxTime = max(time,maxTime);
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && grid[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},time+1});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};