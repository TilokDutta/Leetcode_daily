class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n-1; i++){
            int pick = nums[i];
            if(i != 1) pick += prev2;
            int notPick = 0 + prev1;
            int curr = max(pick,notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        int aprev1 = nums[1];
        int aprev2 = 0;
        for(int i = 2; i < n; i++){
            int pick = nums[i];
            if(i != 1) pick += aprev2;
            int notPick = 0 + aprev1;
            int curr = max(pick,notPick);
            aprev2 = aprev1;
            aprev1 = curr;
        }
        return max(aprev1,prev1);
    }
};
