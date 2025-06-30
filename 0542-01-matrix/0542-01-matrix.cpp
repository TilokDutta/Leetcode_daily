class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        queue< pair < pair<int,int>, int > > q;
        vector<vector<int>> ans(r,vector<int>(c,0));
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i = 0 ;i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr >= 0 && nr < r && nc >= 0 && nc < c && vis[nr][nc] == 0){
                    ans[nr][nc] = dist + 1;
                    q.push({{nr,nc},dist+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};