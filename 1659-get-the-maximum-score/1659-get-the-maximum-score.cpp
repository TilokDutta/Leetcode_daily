class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        long long res = 0;
        int mod = 1e9 + 7;
        while( i < n && j < m){
            if(nums1[i] < nums2[j]){
                sum1 += nums1[i];
                sum1 %= mod;
                i++;
            }else if (nums1[i] > nums2[j]){
                sum2 += nums2[j];
                sum1 %= mod;
                j++;
            }else{
                res += max(sum1,sum2) + nums1[i]; 
                res %= mod;
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        while(j < m){
            sum2 += nums2[j];
            j++;
        }
        while(i < n){
            sum1 += nums1[i];
            i++;
        }
        res += max(sum1,sum2);
        res %= mod;
        return res ;
    }
};