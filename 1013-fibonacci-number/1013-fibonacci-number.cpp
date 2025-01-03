class Solution {
public:
    int fib(int n) {
        vector<int> v(n+1);
        for(int i = 0; i <= n; i++){
            if(i == 0 || i==1) v[i] = i;
            else{
                v[i] = v[i-1] +v[i-2];
            }
        }
        return v[n];
    }
};