class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
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