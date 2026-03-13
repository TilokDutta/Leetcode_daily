class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sumu = accumulate(nums.begin(),nums.end(),0LL), prod = 1;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            sumu = sumu - nums[i];
            if(sumu == prod){
                return i;
            }
            if(prod > sumu) break;
            if(prod > 1e18 / nums[i]) break;
            prod *= nums[i];
        }
        return -1;
    }
};