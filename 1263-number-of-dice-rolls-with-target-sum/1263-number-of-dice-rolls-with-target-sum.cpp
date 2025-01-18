#define ll  long long int
#define mod 1000000007

class Solution {
public:
    vector<vector<ll> > dp;
    int f(int n, int k, int target){
        if(n == 0 and target == 0) return 1;
        if(n == 0) return 0;
        int sum = 0;
        if(dp[n][target] != -1) return dp[n][target];
        for(int v = 1; v <= k; v++){
            if(target-v < 0) continue;
            sum = ((sum % mod) + (f(n-1,k,target-v) % mod));
        }
        return dp[n][target] = sum % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35,vector<ll>(1005,-1));
        int ans = f(n,k,target);
        return ans;
    }
}; 