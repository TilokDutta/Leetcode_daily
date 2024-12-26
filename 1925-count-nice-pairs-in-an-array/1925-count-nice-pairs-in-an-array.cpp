class Solution {
public:
    int reverse(int num){
        int x = 0;
        while(num >0){
            x = x*10 + num % 10;
            num = num/10;
        }
        return x;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int MOD = 1e9 + 7;
        unordered_map<int,int> mp;

        for(int i = 0; i  < n; i++){
            int root = nums[i] - reverse(nums[i]);
            cnt = (cnt + mp[root]) % MOD;
            mp[root]++;
        }
        return cnt;
    }
};