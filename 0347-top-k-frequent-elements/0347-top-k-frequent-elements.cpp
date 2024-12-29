class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int el : nums){
            mp[el]++;
        }
        priority_queue<pi> pq;
        for(auto elem : mp){
            pq.push({elem.second,elem.first});
            // if(pq.size() > k){
            //     pq.pop();
            // }
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};