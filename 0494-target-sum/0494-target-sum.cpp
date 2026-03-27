class Solution {
public:
    int f(int ind, int target, int sum, vector<int> &nums){
        if(ind == 0){
            int count = 0;
            if(sum + nums[0] == target) count++;  
            if(sum - nums[0] == target) count++;  
            return count;
        }
        int sub = f(ind-1,target,sum-nums[ind],nums);
        int add = f(ind-1,target,sum+nums[ind],nums);
        return sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return f(nums.size() - 1, target,0,nums);
    }
};