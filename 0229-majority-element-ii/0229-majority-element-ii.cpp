class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int maj1 = NULL;
        int maj2 = NULL;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(maj1 == nums[i]){
                cnt1++;
            }else if(maj2 == nums[i]){
                cnt2++;
            }else if(cnt1 == 0){
                maj1 = nums[i];
                cnt1 = 1;
            }else if(cnt2 == 0){
                maj2 = nums[i];
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maj1){
                count1++;
            }else if(nums[i] == maj2){
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > n/3) ans.push_back(maj1);
        if(count2 > n/3) ans.push_back(maj2);
        return ans;
    }
};