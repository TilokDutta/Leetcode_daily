class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int count = 1;
        while(left <= right && top <= down){
            // filled the upper row
            for(int i = left; i <= right; i++){
                res[top][i] = count;
                count++;
            }
            top++;
            // now fill the right col
            for(int i = top; i <= down; i++){
                res[i][right] = count;
                count++;
            }
            right--;
            // fill the down row
            if(top <= down){
                for(int i = right; i >= left; i--){
                    res[down][i] = count;
                    count++;
                }
                down--;
            }
            
            //fill the left col
            if(right >= left){
                for(int i = down; i >= top; i--){
                    res[i][left] = count;
                    count++;
                }
                left++;
            }
        }
        return res;
    }
};