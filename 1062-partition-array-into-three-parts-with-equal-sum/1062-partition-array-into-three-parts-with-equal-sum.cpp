class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        long long pfsum = 0;
        int cnt = 0;
        if(sum %3 == 0){
            for(int i = 0; i < n; i++){
                if(cnt == 2){
                    return true;
                }
                pfsum += arr[i];
                if(pfsum == sum/3){
                    pfsum = 0;
                    cnt++;
                }
            }
        }
        return false;
    }
};