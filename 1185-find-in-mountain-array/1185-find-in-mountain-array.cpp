/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n-1;
        int peak = -1;
        while(low < high){
            int mid = (low+high) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        peak = low;
        //searching in the previous part of the mountain
        low = 0;
        high = peak;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) {
                return mid; // Target found in ascending part
            } else if (midValue < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Step 3: Search in the descending part
        low = peak + 1;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) {
                return mid; // Target found in descending part
            } else if (midValue > target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Target not found
        return -1;
    }
};