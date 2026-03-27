class Solution {
public:
    int f(int ind,int target, vector<int> &coins, vector<vector<int>> &dp){
        if(target == 0) return dp[ind][target] = 0;
        if(ind  == 0){
            if(target % coins[ind] == 0) return dp[ind][target] = target/coins[ind];
            else return dp[ind][target] = 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = 0 + f(ind-1,target,coins,dp);
        int take = INT_MAX;
        if(target >= coins[ind]){
            take = 1 + f(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if(amount == 0) return 0;
        int ans = f(n-1,amount,coins,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};