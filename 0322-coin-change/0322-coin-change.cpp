class Solution {
public:
    int f(int x,vector<int>& coins,vector<int>& dp){
        if(x == 0) return 0;
        if(dp[x] != -2) return dp[x];
        int ans = INT_MAX; 
        for(int i = 0;i < coins.size();i++){
            if(x < coins[i]) continue;
            ans = min(ans,f(x-coins[i],coins,dp));
        }
        if( ans == INT_MAX) return dp[x] = INT_MAX;
        return dp[x] = ans + 1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1000006,-2);
        int res = f(amount,coins,dp);
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};