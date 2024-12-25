class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num != 0){
            int digit = num% 10;
            rev = rev*10 + digit;
            num = num / 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
            int rev = reverse(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }
};