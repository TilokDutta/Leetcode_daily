class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            string sub = s.substr(i,10);
            mp[sub]++;
        }
        vector<string> res;
        for(auto elem : mp){
            if (elem.second > 1){
                res.push_back(elem.first);
            }
        }
        return res;
    }
};