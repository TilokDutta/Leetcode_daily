class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        int n = strs.size();
        vector<string> temp = strs;
        for(int i = 0; i < n; i++){
            sort(temp[i].begin(),temp[i].end());
        }
        for(int i = 0; i < n; i++){
            mp[temp[i]].push_back(i);
        }
        vector<vector<string>> res;
        for(auto it : mp){
            vector<string> ans;
            vector<int> mapped = it.second;
            for(int j = 0; j < mapped.size(); j++){
                ans.push_back(strs[mapped[j]]);
            }
            res.push_back(ans);
        }
        return res;
    }
};