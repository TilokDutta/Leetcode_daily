class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        vector<vector<int>> height(r,vector<int>(c,-1));
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = x + drow[k];
                int ncol = y + dcol[k];               
                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && height[nrow][ncol] == -1) {
                    height[nrow][ncol] = height[x][y] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return height;
    }
};