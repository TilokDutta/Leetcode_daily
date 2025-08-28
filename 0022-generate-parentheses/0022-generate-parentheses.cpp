class Solution {
public:
    void f(vector<string>& res, int n, int open, int close, string cur){
        if(open == n && close == n){
            res.push_back(cur);
            return;
        }
        if(open < n){
            f(res,n,open+1,close,cur+"(");
        }
        if(close < open){
            f(res,n,open,close+1,cur+")");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(res,n,0,0,"");
        return res;
    }
};