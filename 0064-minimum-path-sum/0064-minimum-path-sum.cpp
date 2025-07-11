class Solution {
public:
    int f(int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(m < 0 || n < 0) return 40000; // beacuse max grid[i][j] value if 200
        if(m == 0 && n == 0 ){
            return grid[0][0];
        }
        if(dp[m][n] != -1) return dp[m][n];
        int left = grid[m][n] + f(m,n-1,grid,dp);
        int top = grid[m][n] + f(m-1,n,grid,dp);
        return dp[m][n] = min(left,top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};