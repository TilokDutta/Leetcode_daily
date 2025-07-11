class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        int prev1 = nums[0];
        int prev2 = nums[0];
        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i != 1 ) pick += prev2;
            int notPick = 0 + prev1;
            int curr = max(pick,notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};