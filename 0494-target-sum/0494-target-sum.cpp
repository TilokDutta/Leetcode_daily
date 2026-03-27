class Solution {
public:
    int f(int ind, int target, int sum, vector<int>& nums, vector<vector<int>>& dp, int total){
        if(ind == 0){
            int count = 0;
            if(sum + nums[0] == target) count++;
            if(sum - nums[0] == target) count++;
            return dp[ind][sum + total] = count;
        }
        if(dp[ind][sum + total] != -1) return dp[ind][sum + total];
        int sub = f(ind-1, target, sum - nums[ind], nums, dp, total);
        int add = f(ind-1, target, sum + nums[ind], nums, dp, total);
        return dp[ind][sum + total] = sub + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        // if(abs(target) > total) return 0;
        vector<vector<int>> dp(n, vector<int>(2*total+1, -1));
        return f(n-1, target, 0, nums, dp, total);
    }
};