class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(auto elem : arr1){
            bool flag = true;
            for(auto el : arr2){
                if(abs(elem-el) <= d){
                   flag = false;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};