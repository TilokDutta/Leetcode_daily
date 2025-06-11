class Solution {
public:
    vector<int> merge(vector<int>& nums1, int left, vector<int>& nums2, int right){
        vector<int> temp;
        int n = nums1.size();
        int m = nums2.size();

        while(left < n && right < m){
            if(nums1[left] <= nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }else{
                temp.push_back(nums2[right]);
                right++;
            }
        }
        while(left < n){
            temp.push_back(nums1[left]);
            left++;
        }
        while(right < m){
            temp.push_back(nums2[right]);
            right++;
        }

        return temp;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray = merge(nums1,0,nums2,0);
        int low = 0;
        int high = mergedArray.size();
        int mid = (low+high)/2;
        double median = mergedArray[mid];
        if(high % 2 == 0){
            int midNext = mid - 1;
            median = (mergedArray[mid] + mergedArray[midNext]) / 2.0;
        }
        return median;
    }
};
