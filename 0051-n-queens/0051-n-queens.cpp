class Solution {
public:
    bool isPossible(int col, int row, vector<string> boards, int n){
        int dupcol = col;
        int duprow = row;
        while(row >= 0 && col >= 0){
            if(boards[row][col] == 'Q') return false;
            col--;
            row--;
        }
        row = duprow;
        col = dupcol;
        while(col >= 0){
            if(boards[row][col] == 'Q') return false;
            col--;

        }
        row = duprow;
        col = dupcol;
        while(row < n && col >= 0){
            if(boards[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& boards, int col, int n){
        if(col == n){
            ans.push_back(boards);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isPossible(col,i,boards,n)){
                boards[i][col] = 'Q';
                solve(ans,boards,col+1,n);
                boards[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> boards(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i = 0; i < n; i++){
            boards[i] = s;
        }
        solve(ans,boards,0,n);
        return ans;
    }
};