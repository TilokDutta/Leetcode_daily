class Solution {
public:
    int f(int ind, int target, vector<int>& arr,vector<vector<int>> &dp){
        if(target == 0) return dp[ind][target] = 1;
        if(ind == 0){
            if(arr[ind] == target) return dp[ind][target] = 1;
            else return dp[ind][target] = 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f(ind-1,target,arr,dp);
        bool take = 0;
        if(target >= arr[ind]){
            take = f(ind-1,target-arr[ind],arr,dp);
            
        }
        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target % 2 != 0) return false;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return f(n-1,target/2,nums,dp);
    }
};