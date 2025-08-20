class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1) return 0;
        int maxGap = INT_MIN;
        for(int i = 1; i < n; i++){
            maxGap = max((nums[i]-nums[i-1]), maxGap);
        }
        return maxGap;
    }
};