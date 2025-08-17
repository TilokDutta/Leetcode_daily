class Solution {
public:
    int solve(int n) {
        int count = 0;
        while(n){
            n = n & (n-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i = 0; i <= n; i++){
            res[i] = solve(i);
        }
        return res;
    }
};