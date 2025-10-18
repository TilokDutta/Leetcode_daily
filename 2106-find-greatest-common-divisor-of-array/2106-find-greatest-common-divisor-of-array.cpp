class Solution {
public:
    int getGcd(int a,int b){
        if(b == 0) return a;
        return getGcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return getGcd(nums[0],nums[nums.size() - 1]);
    }
};