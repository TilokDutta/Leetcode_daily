class Solution {
public:
    int helper(int n, vector<int>& v){
        if(n == 0 || n == 1) return n;
        if(v[n] != -1) return v[n];
        int ans = helper(n-1,v) + helper(n-2,v);
        v[n] = ans;
        return ans;
    }
    int fib(int n) {
        vector<int> v(n+1,-1);
        return helper(n,v);
    }
};