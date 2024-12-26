class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i = 0;i < s.size(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(auto x: mp1){
            char ch = x.first;
            if(mp2[ch] != x.second)   return false;     
        }
        return true;
    }
};

