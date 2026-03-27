class Solution {
public:
    int f(int ind,int target, vector<int> &nums){
        if(ind == 0){
            if(target ==0 && nums[ind] == 0) return 2;
            if(target == 0) return 1;
            return target == nums[ind];
        }
        int notTake = f(ind-1,target,nums);
        int take = 0;
        if(target >= nums[ind]){
            take = f(ind-1,target-nums[ind],nums);
            
        }
        return take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total - target < 0 || (total - target) %2 != 0) return 0;
        int tar = (total-target)/2;
        return f(n-1,tar,nums);
    }
};