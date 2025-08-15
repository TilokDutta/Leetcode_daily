class Solution {
public:
    int dp[1001][1001];
    int isPalindrome(string &s, int left, int right){
        if(left >= right) return 1;
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        if(s[left] == s[right]){
            return dp[left][right] = isPalindrome(s,left+1,right-1);
        }
        return dp[left][right] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int length = 0;
        string ans;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1 > length){
                        ans = s.substr(i,j-i+1);
                    }
                    length = max(length,j-i+1);
                }
            }
        }
        return ans;
    }
};