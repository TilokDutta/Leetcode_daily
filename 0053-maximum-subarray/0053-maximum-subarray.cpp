class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0];
        long long csum = nums[0];
        for(int i = 1; i < n; i++){
            csum = max(csum + nums[i],(long long)nums[i]);
            sum = max(csum,sum);
        }
        return sum;
    }
};