class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,2);
        vector<int> right(n,2);
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                left[i] = left[i-1] +1;
            }
        }
        for(int i = n-3 ; i >= 0; i--){
            if(nums[i+2]-nums[i+1] == nums[i+1] - nums[i]){
                right[i] = right[i+1] + 1;
            }
        }
        int ans = 2;
        for(int i = 0; i < n; i++){
            ans = max(ans,max(left[i],right[i]));
            if(i == 0){
                ans = max(ans,right[i+1] + 1);
            }
            else if(i == n-1){
                ans = max(ans, left[i-1]+1);
            }
            else{
                ans = max(ans, left[i-1] +1);
                ans = max(ans, right[i+1] +1);
                if((nums[i+1] -nums[i-1]) % 2 == 0){
                    int req = (nums[i+1] -nums[i-1])/2;
                    int leftlen = 1; int rightlen = 1;
                    if(i >= 2 && (nums[i-1]-nums[i-2] == req)){
                        leftlen = left[i-1];
                    }
                    if(i <= n-3 && (nums[i+2] - nums[i+1] == req)){
                        rightlen = right[i+1];
                    }
                    ans = max(ans, leftlen+rightlen+1);
                }
            } 
        }
        return ans;
    }
};