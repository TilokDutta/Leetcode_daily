class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,int> mp;
        for(auto ch : s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto ele : mp){
            pq.push({ele.second,ele.first});
        }
        while(!pq.empty()){
            pair<int,char> n = pq.top();
            pq.pop();
            for(int i = 0; i < n.first; i++){
                res += n.second;
            }
        }
        return res;
    }
};