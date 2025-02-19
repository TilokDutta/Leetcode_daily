class Solution {
public:
    bool solve(vector<int> &nums, long long sum,int i,vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(i == 0) return (nums[0] == sum);
        if(dp[i][sum] != -1) return dp[i][sum];
        bool notTake = solve(nums,sum,i-1,dp);
        bool take = false;
        if(sum >= nums[i]){
            take = solve(nums,sum-nums[i],i-1,dp);
        }
        return dp[i][sum] = notTake | take;
    }
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
        if(sum % 2 != 0) return false;
        return solve(nums,sum/2,n-1,dp);
    }
};