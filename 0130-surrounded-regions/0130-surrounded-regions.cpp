class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = 1;
        board[r][c] = '#';
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        for(int i = 0; i < 4; i++){
            int nr = r + drow[i]; 
            int nc = c + dcol[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && board[nr][nc] == 'O'){
                dfs(nr,nc, board,vis);
            } 
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for (int i = 0 ; i < m; i++){
            if( !vis[0][i] && board[0][i] == 'O'){
                dfs(0,i,board,vis);
            }
            if( !vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1,i,board,vis);
            }
        }
        for(int i = 1; i < n-1; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,board, vis);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};