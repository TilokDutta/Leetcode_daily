class Solution {
public:
    int avg(vector<vector<int>>& img, int i, int j){
        int ans = img[i][j];
        int n = 1;
        int rol = img.size();
        int col = img[0].size();
        if(j-1 >= 0){
            ans += img[i][j-1];
            n++;
        }
        if(j+1 < col) {
            ans += img[i][j+1]; 
            n++;
        }
        if(i-1 >= 0 && j-1 >= 0) {
            ans += img[i-1][j-1]; 
            n++;
        }
        if(i-1 >= 0 && j+1 < col){ 
            ans += img[i-1][j+1]; 
            n++;
        }
        if(i+1 < rol && j+1 < col) {
            ans += img[i+1][j+1]; 
            n++;
        }
        if(i-1 >= 0) {
            ans += img[i-1][j]; 
            n++;
        }
        if(i+1 < rol) {
            ans += img[i+1][j]; 
            n++;
        }
        if(i+1 < rol && j-1 >= 0){ 
            ans += img[i+1][j-1];
            n++;
        }
        ans /= n;
        return ans;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rol = img.size();
        int col = img[0].size();
        vector<vector<int>> res(rol,vector<int>(col));
        for(int i = 0; i < rol; i++){
            for(int j = 0; j < col; j++){
                res[i][j] = avg(img,i,j);
            }
        }
        return res;
    }
};