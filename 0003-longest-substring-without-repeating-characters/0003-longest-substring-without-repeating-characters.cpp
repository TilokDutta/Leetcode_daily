class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, len = 0;
        vector<int> mpp(256,-1);
        while(right < s.length()){
            if(mpp[s[right]] != -1){
                left = max(mpp[s[right]]+1, left);
            }
            mpp[s[right]] = right;
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
};