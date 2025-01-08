class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int ind){
        int n = nums.size();
        if(ind == n-1) return nums[ind];
        if(ind == n-2) return max(nums[ind],nums[ind+1]);
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max((nums[ind]+helper(nums,ind+2)),(0+helper(nums,ind+1)));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        int ans = helper(nums,0);
        return ans;
    }
};