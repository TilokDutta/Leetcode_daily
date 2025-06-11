class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& boards, int col, int n, vector<int>& leftrow, vector<int>& lowerdia, vector<int>& upperdia){
        if(col == n){
            ans.push_back(boards);
            return;
        }
        for(int row = 0; row < n; row++){
            if(leftrow[row] == 0 && lowerdia[row+col] == 0 && upperdia[n-1+col-row] == 0){
                leftrow[row] = 1;
                lowerdia[row+col] = 1;
                upperdia[n-1+col-row] = 1;
                boards[row][col] = 'Q';
                solve(ans,boards,col+1,n, leftrow,lowerdia,upperdia);
                leftrow[row] = 0;
                lowerdia[row+col] = 0;
                upperdia[n-1+col-row] = 0;
                boards[row][col] = '.';
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
        vector<int> leftrow(n,0);
        vector<int> lowerdia(2*n-1,0);
        vector<int> upperdia(2*n-1,0);
        solve(ans,boards,0,n,leftrow, lowerdia, upperdia);
        return ans;
    }
};