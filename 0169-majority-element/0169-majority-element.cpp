class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int maj = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(count == 0){
                maj = nums[i];
                count = 1;
            }else if( maj == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maj){
                cnt++;
            }
        }
        if(cnt > n/2){
            return maj;
        }
        return -1;
    }
};