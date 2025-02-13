class Solution {
public:
    long long helper(vector<vector<int>>& a,int i,int j,vector<vector<int>>& dp){
        if(i == a.size()-1) return dp[i][j]=a[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = a[i][j] + helper(a,i+1,j,dp);
        int dg = a[i][j] + helper(a,i+1,j+1,dp);
        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& a) {
        int r = a.size();
        if(r==0) return 0;
        vector<vector<int>> dp(r,vector<int> (r,-1));
        return helper(a,0,0,dp);
    }
};