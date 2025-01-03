class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = nums[(n-1) / 2];
        int count = 0;
        for(int elem : nums){
            count += abs(elem - mid);
        }
        return count;
    }
};