class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> check(n+1,false);
        for(int i = 0; i < n ; i++){
            if(nums[i] <= n && nums[i] > 0){
                check[nums[i]] = true;
            }
        }
        for(int i = 1; i < n+1; i++){
            if(check[i] == false) return i;
        }
        return n+1;
    }
};