class Solution {
public:
    long long helper(vector<vector<int>>& a,int i,int j,vector<vector<int>>& dp){
        if(i == a.size()-1) return dp[i][j]=a[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int d = a[i][j] + helper(a,i+1,j,dp);
        int dlg = INT_MAX;
        if(j-1>=0){
            dlg = a[i][j] + helper(a,i+1,j-1,dp);
        }
        int drg = INT_MAX;
        if(j+1 < a[0].size()){
            drg = a[i][j] + helper(a,i+1,j+1,dp);
        }
        return dp[i][j]=min(d,min(drg,dlg));
    }
    int minFallingPathSum(vector<vector<int>>& m) {
        int r = m.size();
        if(r==0) return 0;
        int c = m[0].size();
        vector<vector<int>> dp(r,vector<int> (c,-1));
        for(int i = 0; i < c; i++){
            dp[0][i] = m[0][i];
        }
        for(int i = 1; i < r; i++){
            for(int j = 0; j < c; j++){
                if(j-1 >= 0 && j+1 < c){
                    dp[i][j] = m[i][j] + min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                }else if(j-1 >= 0){
                    dp[i][j] = m[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }else if(j+1 < c){
                    dp[i][j] = m[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
            }
        }
        int minSum = INT_MAX;
        for(int i = 0; i < c; i++){
            minSum = min(minSum,dp[r-1][i]);
        }
        return minSum;
    }
};