class Solution {
public:
    vector<vector<int>> res;
    void f(int n, int k,vector<int>& ans,int i){
        if(n == 0 && k == 0){
            res.push_back(ans);
            return;
        }
        if(n > i){
            for(int j = i+1; j <= 9; j++){
                ans.push_back(j);
                f(n-j,k-1,ans,j);
                ans.pop_back();
            }
        }
        return; 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        f(n,k,ans,0);
        return res;
    }
};