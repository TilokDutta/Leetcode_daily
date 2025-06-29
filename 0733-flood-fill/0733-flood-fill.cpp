class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &vis, int color, vector<vector<int>> &ans){
        int n = vis.size();
        int m = vis[0].size();
        vis[r][c] = 1;
        ans[r][c] = color;
        int dcol[] = {-1,0,1,0};
        int drow[] = {0,-1,0,1};
        for(int i = 0; i < 4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr < n && nr >= 0 && nc < m && nc >= 0){
                if(vis[nr][nc] == 0){
                    dfs(nr,nc,vis,color,ans);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int srcCol = image[sr][sc];
        vector<vector<int>> vis(row,vector<int>(col,-1));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(image[i][j] == srcCol){
                    vis[i][j] = 0;
                }
            }
        }
        vector<vector<int>> ans = image;
        dfs(sr,sc,vis,color,ans);
        return ans;
    }
};