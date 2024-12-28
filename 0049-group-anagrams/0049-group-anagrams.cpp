class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i = 0; i < arr.size(); i++){
            string temp  = arr[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(arr[i]);
        }
        for(auto elem: mp){
            res.push_back(elem.second);
        }
        return res;
    }
};