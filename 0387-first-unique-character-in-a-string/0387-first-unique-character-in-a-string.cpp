class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto elem : s){
            mp[elem]++;
        }
        int res = -1;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] == 1){
                res = i;
                break;
            }
        }
        return res;
    }
};