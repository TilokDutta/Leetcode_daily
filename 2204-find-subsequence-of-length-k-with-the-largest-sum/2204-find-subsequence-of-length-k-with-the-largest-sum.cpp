class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            pq.push({nums[i],i});
        }
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(),res.end());
        vector<int> ans;
        for(auto elem : res){
            ans.push_back(nums[elem]);
        }
        return ans;
    }
};