class Solution {
public:
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0) return 1;
            if(arr[0] == target) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = f(ind-1, target, arr, dp);
        int take = 0;
        if(target >= arr[ind])
            take = f(ind-1, target - arr[ind], arr, dp);
        return dp[ind][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        // assigning + to s1 subset, - to s2 subset
        // s1 - s2 = target, s1 + s2 = total
        // => s1 = (total + target) / 2
        if((total + target) < 0 || (total + target) % 2 != 0) return 0;
        int s1 = (total + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(s1+1, -1));
        return f(n-1, s1, nums, dp);
    }
};