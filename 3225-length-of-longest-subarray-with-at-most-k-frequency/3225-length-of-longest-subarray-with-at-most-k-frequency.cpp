class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxL = INT_MIN;
        for(int j = 0; j < n; j++){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            maxL = max(maxL,j-i+1);
        }
        return maxL;
    }
};