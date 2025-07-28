class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<vector<int>,int>> q;
        int entryR = entrance[0];
        int entryC = entrance[1];
        vis[entryR][entryC] = 1;
        q.push({entrance,0});
        int count = -1;
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first[0];
            int c = q.front().first[1];
            int level = q.front().second;
            q.pop();
            if((r == 0 || r == n-1 || c== 0 || c == m-1) && !(r == entryR && c == entryC)){
                count = level;
                break;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && maze[nr][nc] == '.'){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},level+1});
                }
            }
        }
        return count;
    }
};