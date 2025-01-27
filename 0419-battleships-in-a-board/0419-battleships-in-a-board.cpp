class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int r = b.size();
        int c = b[0].size();
        int cnt = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(b[i][j] == 'X'){
                    if((i == 0 || b[i-1][j] != 'X') && (j == 0 || b[i][j-1] != 'X')){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};