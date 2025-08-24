class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = INT_MIN;
        int hash[26] = {0};
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxf = INT_MIN;
        while(r < n){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            while( ( (r-l) + 1 ) - maxf > k){
                hash[s[l] - 'A']--;
                maxf = 0;
                for(int i = 0; i < 25; i++){
                    maxf = max(maxf,hash[i]);
                }
                l++;
            }
            if(r-l+1 - maxf <= k){
                maxLength = max(maxLength, r-l+1);
            }
            r++;
        }
        return maxLength;
    }
};