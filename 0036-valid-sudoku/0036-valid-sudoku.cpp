class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<char>> row;
        unordered_map<int,set<char>> col;
        unordered_map<int,set<char>> square;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char curr = board[i][j];
                if(curr == '.') continue;
                if(row[i].count(curr)) return false;
                if(col[j].count(curr)) return false;
                int sqInd = (i/3)*3 + j/3;
                if(square[sqInd].count(curr)) return false;

                row[i].insert(curr);
                col[j].insert(curr);
                square[sqInd].insert(curr);
            }
        }
        return true;
    }
};