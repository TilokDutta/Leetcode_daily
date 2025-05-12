class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = m.size();
        int c = m[0].size();

        int low = 0;
        int high = r*c - 1;

        while(low <= high){
            int mid = low + (high-low)/2;
            int midElem = m[mid/c][mid%c];

            if(midElem == t){
                return true;
            }else if(midElem < t) low = mid+1;
            else high = mid-1;
        }
        
        return false;
    }
};