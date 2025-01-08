class Solution {
public:
    // vector<int> dp;
    // int helper(vector<int>& nums, int ind){
    //     int n = nums.size();
    //     if(ind == n-1) return nums[ind];
    //     if(ind == n-2) return max(nums[ind],nums[ind+1]);
    //     if(dp[ind] != -1) return dp[ind];
    //     return dp[ind] = max((nums[ind]+helper(nums,ind+2)),(0+helper(nums,ind+1)));
    // }
    int fbu(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2],nums[n-1]);
        for(int i = n-3; i>=0; i--){
             dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        // dp.clear();
        // dp.resize(105,-1);
        int ans = fbu(nums);
        return ans;
    }
};