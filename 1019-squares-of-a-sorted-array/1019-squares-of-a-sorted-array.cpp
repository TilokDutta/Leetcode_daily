class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int pos = n-1;
        vector<int> temp(n);
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                temp[pos] = nums[left]*nums[left];
                pos--;
                left++;
            }else{
                temp[pos] = nums[right]* nums[right];
                pos--;
                right--;
            }
        }
        return temp;
    }
};