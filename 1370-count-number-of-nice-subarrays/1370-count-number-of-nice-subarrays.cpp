class Solution {
public:
    int helper(vector<int>& nums, int k){
        int l=0;int r = 0;
        int sum = 0;
        int count = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
        }
        int res = helper(nums,k);
        int res1 = helper(nums,k-1);
        return res - res1;
    }
};