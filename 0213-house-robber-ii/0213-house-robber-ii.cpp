class Solution {
public:
    int helper(vector<int> dup){
        int n = dup.size();
        if(n == 0) return 0;
        if(n == 1) return dup[0];
        vector<long long> dp(105);
        dp[0] = dup[0];
        dp[1] = max(dup[1],dup[0]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dup[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dup(nums.begin(),nums.end()-1);
        long long sum1 = helper(dup);
        vector<int> dup2(nums.begin()+1,nums.end());
        long long sum2 = helper(dup2);
        return max(sum1,sum2);
    }
};