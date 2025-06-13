class Solution {
private:
    bool dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, string& word, int index) {
        int n = board.size();
        int m = board[0].size();

        if(index == word.size()) return true; // if the whole word is found

        if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col] == 1 || board[row][col] != word[index])
            return false; // out of bounds, visited, or character mismatch

        vis[row][col] = 1; // mark as visited

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(dfs(nrow, ncol, vis, board, word, index + 1)) {
                return true;
            }
        }

        vis[row][col] = 0; // backtrack
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) { // check if starting char matches
                    if(dfs(i, j, vis, board, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};