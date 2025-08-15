class Solution {
public:
    bool solve(string &s, int left, int right){
        if(left >= right) return true;
        if(s[left] == s[right]){
            return solve(s,left+1,right-1);
        }
        return false;
    }
    bool isPalindrome(int x) {
        string num = to_string(x);
        int n = num.size();
        return solve(num,0,n-1);
    }
};