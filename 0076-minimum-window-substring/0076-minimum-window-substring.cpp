class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";
        unordered_map<char,int> mp;
        for(int i = 0; i < m; i++){
            mp[t[i]]++;
        }
        int countReq = m;
        int i = 0; int j = 0;
        int minSize = INT_MAX;
        int start = 0;
        while(j < n){
            if(mp[s[j]] > 0){
                countReq--;
            }
            while(countReq == 0){
                if(j-i+1 < minSize){
                    minSize = j-i+1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    countReq++;
                }
                i++;
            }
            mp[s[j]]--;
            j++;
        }
        return (minSize == INT_MAX) ? "" : s.substr(start,minSize);
    }
};