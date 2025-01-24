class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int size  = nums[0].size();
        vector<int> ans;
        for(auto elem : queries){
            int k = elem[0];
            int trim = elem[1];
            vector<pair<string,int>> v_ind;
            for(int i = 0; i < n; i++){
                string trimmed = nums[i].substr(size - trim);
                v_ind.push_back({trimmed,i});
            }
            sort(v_ind.begin(),v_ind.end());
            ans.push_back(v_ind[elem[0]-1].second);
        }
        return ans;
    }
};